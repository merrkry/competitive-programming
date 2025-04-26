#! /usr/bin/env python

import os
import tempfile
import subprocess
import atexit
import argparse


def main() -> None:
    parser = argparse.ArgumentParser(
        "judge given program with input and expected output",
        usage="use --help for more information",
        formatter_class=argparse.RawTextHelpFormatter,
    )

    parser.add_argument("src_path", help="Path to source file")
    parser.add_argument(
        "input_path",
        nargs="?",
        default=None,
        help="""\
Path to input file, optional.
The .in file with same name as source file in the same directory will be used if not specified.""",
    )
    parser.add_argument(
        "sample_path",
        nargs="?",
        default=None,
        help="""\
Path to sample output file, optional.
The .out file with same name as source file in the same directory will be used if not specified.""",
    )

    parser.add_argument(
        "-s",
        "--always-show-output",
        action="store_true",
        help="Always print output to console even if sample output is given",
    )

    args = parser.parse_args()

    def is_valid_path(path: str) -> bool:
        return os.path.isfile(path)

    src_path = args.src_path
    if not is_valid_path(src_path):
        print("Error: invalid source file")
        exit(1)
    src_name_full = os.path.basename(src_path)
    src_name = os.path.splitext(src_name_full)[0]
    src_suffix = os.path.splitext(src_name_full)[1]
    if src_suffix != ".cpp":
        print("Error: unsupported language")
        exit(1)

    if args.input_path == None:
        input_path = os.path.splitext(src_path)[0] + ".in"
    else:
        input_path = args.input_path
    if not is_valid_path(input_path):
        print("Error: invalid input file")
        exit(1)

    sample_path = args.sample_path
    if sample_path == None:
        auto_sample_path = os.path.splitext(src_path)[0] + ".out"
        if is_valid_path(auto_sample_path):
            sample_path = auto_sample_path
    else:
        if not is_valid_path(sample_path):
            print("Error: invalid sample output file")
            exit(1)
    output_to_file = sample_path != None
    output_to_console = (not output_to_file) or args.always_show_output

    with tempfile.TemporaryDirectory() as temp_dir:
        print("COMPILATION:\n")

        binary_path = os.path.join(temp_dir, src_name)

        # https://2025.gcpc.nwerc.eu/system
        cmd = [
            "g++",
            "-x",
            "c++",
            "-std=gnu++2b",
            "-Wall",
            "-O2",
            # "-static", # requires static version of compiler
            "-pipe",
            "-DONLINE_JUDGE",
            "-DDOMJUDGE",
            "-o",
            binary_path,
            src_path,
        ]

        try:
            subprocess.run(cmd, check=True, stdout=None, stderr=None)
        except Exception:
            print("Error: compilation failed")
            exit(1)

        print("\nJUDGE:\n")

        try:
            input_process = subprocess.Popen(
                ["cat", input_path], stdout=subprocess.PIPE, text=True
            )
            atexit.register(input_process.kill)

            calc_cmd = [binary_path]
            calc_process = subprocess.Popen(
                calc_cmd,
                stdin=input_process.stdout,
                stdout=subprocess.PIPE,
                stderr=None,
                text=True,
            )
            atexit.register(calc_process.kill)
            assert calc_process.stdout is not None

            output_file = None
            output_path = os.path.join(temp_dir, src_name + ".out")
            if output_to_file:
                output_file = open(output_path, "w")
                atexit.register(output_file.close)

            while True:
                line = calc_process.stdout.readline()
                if not line:
                    break
                if output_to_console:
                    print(line.strip())
                if output_file != None:
                    output_file.write(line)

            input_process.wait()
            if calc_process.wait() != 0:
                raise subprocess.CalledProcessError(calc_process.returncode, calc_cmd)

            if output_file != None:
                output_file.flush()

            if output_file != None:
                print("\nDIFF:\n")
                diff_process = subprocess.Popen(
                    ["diff", "-y", sample_path, output_path], stdout=None, text=True
                )
                atexit.register(diff_process.kill)
                diff_process.wait()
        except Exception as e:
            print("Error: runtime error", e)
            exit(1)


if __name__ == "__main__":
    main()
