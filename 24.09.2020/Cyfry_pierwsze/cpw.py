import re
n = int(input())
for i in range(n):
    print(len(re.findall("2|3|5|7",input())))
