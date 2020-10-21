x = int(input())
y = int(input())
xs = int(input())
ys = int(input())

for i in range(1, y+1):
    if(i != ys):
        print("."*x, end = '')
        print("\n")
    else:
        print("."*(xs-1), end = '')
        print("*", end = '')
        print("."*(x-xs), end = '')
        print("\n")
