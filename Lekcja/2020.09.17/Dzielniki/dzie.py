import math

n = int(input())

for i in range(1, int(math.sqrt(n))):
    if(n % i == 0):
        print(i)

for i in range(int(math.sqrt(n)), 0, -1):
    if(n % i == 0 and n/i != i):
        print(int(n/i))
