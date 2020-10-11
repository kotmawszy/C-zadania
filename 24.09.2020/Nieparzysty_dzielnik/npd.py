import math
n = int(input())
for i in range(2, int(math.sqrt(2 * n + 1))):
    if(n % i != 0):
        continue
    x = n / i
    if(x % 2 == 1):
        print(int(x))
        exit()
print(1)
