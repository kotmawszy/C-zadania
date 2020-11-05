import math

def p(x):
    if(x < 2):
        return False
    for i in range(2, int(math.sqrt(x)+1)):
        if(x % i == 0):
            return False
    return True


n = int(input())
for i in range(n):
    a = int(input())
    while(True):
        if(p(a+1) == True and p(a+3) == True):
            print(a+1, end=" ")
            print(a+3)
            break
        a += 1
