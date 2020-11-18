n = int(input())

while(n + 1 > 1):
    if(n % 2 == 0):
        print("TAK")
        exit()
    n /= 2
print("NIE")
