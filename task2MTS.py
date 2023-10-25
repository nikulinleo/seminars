
def check1(inp):
	a = round(float(inp) * 10000)//100
	q = 1

	for q in range(1,101):
		for p in range(q + 1):
			if ((100 * p) // q == a % 100):
				break
		if p != q:
			p += q * (a // 100)
			return [p, q]
		

def check2(inp):
	a = int(float(inp) * 100)
	q = 1

	for q in range(1,101):
		for p in range(q + 1):
			if ((100 * p) // q == a % 100):
				break
		if p != q:
			p += q * (a // 100)
			return [p, q]

for a in range(1,1000):
	if (check1(a/100)[0]*100//check1(a/100)[1] != check2(a/100)[0]*100//check2(a/100)[1] ): print(a, check1(a/100), check2(a/100))
