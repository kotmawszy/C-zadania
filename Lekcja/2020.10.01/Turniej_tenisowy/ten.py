n = int(input())
s = 0
a = 1
b = 2

while(b <= n):
    s += 1
    c = a + b
    a = b
    b = c
print(s)
