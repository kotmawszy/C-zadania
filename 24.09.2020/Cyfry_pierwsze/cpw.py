n = int(input())

for j in range(n):
    a = 0
    b = input()
    
    for i in range(len(b)):
        if(b[i] == "2" or b[i] == "3" or b[i] == "5" or b[i] == "7"):
            a += 1
    print(a)
