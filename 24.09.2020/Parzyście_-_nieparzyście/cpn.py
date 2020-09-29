s = input()
a=b=0
for i in s:
    if(int(i)%2 == 1):
        a=1
    else:
        b=1
print("TAK" if a==1 and b==1 else "NIE")
