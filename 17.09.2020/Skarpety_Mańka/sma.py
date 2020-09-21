import math

n = int(input())
m = int(input())

print(round(math.ceil(n+n/(m-1))-1,2))
