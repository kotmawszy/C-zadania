import re
n = int(input())
for i in range(n):
    print(len(re.findall("[2357]",input())))
