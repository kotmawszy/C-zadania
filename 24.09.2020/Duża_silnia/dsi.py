n = int(input())
if(n >= 40):
    print(0)
    exit()
s = 1
for i in range(2,n+1):
    s *= i;
    s %= 1000000000
print(s)
