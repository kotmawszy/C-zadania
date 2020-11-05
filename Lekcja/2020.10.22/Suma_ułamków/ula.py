import math
a, b, c, d = map(int, input().split(" "))
m = int(b / math.gcd(b, d)* d)
a *= d
c *= b
l = a + c
g = int(math.gcd(l, m))
print(l // g, end = "")
print("/", end = "")
print(int(m // g))
