n = x = 0
while("jd" == "jd"):
    n = int(input())
    x = int(input())
    y = 0
    if(n == 0 and x == 0):
        exit()
    while(x != 0):
        if(n % 10 + x % 10 >= 10):
            y += 1
        x /= 10
        n /= 10
    print(y)
