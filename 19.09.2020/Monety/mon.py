n = int( input() )
i1 = 0
i0 = 0
for i in range(n):
	x=input()
	if(x == 1):
		i1 += 1
	else:
		i0 += 1

if(i0<i1):
	print(i0)
else:
	print(i1)
