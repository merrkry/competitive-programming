import argparse


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("solution", type=str, help="Path to solution code")
    parser.add_argument("--result", type=str, default="")
    args = parser.parse_args()

    with open(args.solution, "r") as solutionFile:
        solution = solutionFile.read()
        print(solution)

    foo = KeyboardInt


if __name__ == "__main__":
    main()
