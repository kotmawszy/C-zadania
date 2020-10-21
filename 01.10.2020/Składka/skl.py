n = int(input())
for i in range(n):
    x = int(input())
    y = 0
    for j in range(x):
        y += int(input())
    print(y % 1000)
