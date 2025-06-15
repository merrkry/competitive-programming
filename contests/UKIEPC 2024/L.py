num_exercise = int(input())

strs = []
for i in range(0, num_exercise):
    str = input()
    strs.append(str)

for i in range(0, 31):
    if i % 7 == 0:
        print(f"{i // 7 + 1} ", end="")
    s = strs[i % num_exercise]
    if "rest" in s:
        print('\U0001f60e', end="")
    elif "leg" in s:
        print('\U0001f9b5', end="")
    else:
        print("\U0001f4aa", end="")
    if i % 7 == 6:
        print()
