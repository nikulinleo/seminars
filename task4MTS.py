size = int(input())

if size in [0,1]:
	print(0)
elif size == 2:
	print(1)
elif size == 3:
	print(2)
elif size == 4:
	print(4)
else:
	sum = ((size - 1) + ((size - 2) % 3 + 1)) * ((size + 1) // 3) - size + 1
	print(sum % 998244353)