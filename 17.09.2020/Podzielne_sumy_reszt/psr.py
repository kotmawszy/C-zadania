n = int(input())

n += 1

while(True):
	if((n % 5 + n % 7) % 3 == 0):
		print(n)
		break
	n += 1
