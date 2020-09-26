n = int(input())

while(n != 0):
    a = 0
    n -= 1
    b = input()
    
    for i in range(0,len(b)):
        if(b[i] == "2" or b[i] == "3" or b[i] == "5" or b[i] == "7"):
            a += 1
    print(a)
