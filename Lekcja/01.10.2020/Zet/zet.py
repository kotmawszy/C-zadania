n = int(input())

print("*"*n)
for i in range(1,n-1):
    print("."*(n-i-1)+"*"+"."*i)
print("*"*n)
