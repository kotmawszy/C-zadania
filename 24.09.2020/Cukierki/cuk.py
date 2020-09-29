n = int(input())
v = 0
p = 1
for i in range(1,n+1):
    a = int(input())
    if(a%2 == 0 and a > v):
        v = a;
        p = i;
print(p)
