n = input()
n = n[::-1] + n
n = int(n)

while(n>1):
    for i in range(2,int(n+1)):
        if(n % i == 0):
            print(i)
            n /= i
            break
