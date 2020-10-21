n = int(input())
a = 0
y = 1
for i in range(1,n+1):
    x = int(input())
    while(y <= x + 1):
        a += 1
        y *= 2
    print(a)
