def check(prefix):
	same = 11 - 3
	minus1 = min(int(prefix[3]) + 1, 8)
	plus1 = min(10 - int(prefix[3]), 8)

	cntplus = 0
	cntminus = 0
	cntsame = 0
	for i in [2, 1, 0]:
		if (cntsame + i == 2) & (int(prefix[i]) == int(prefix[i+1])): cntsame+=1
		if (cntplus + i == 2) & (int(prefix[i]) == int(prefix[i+1])-1): cntplus+=1
		if (cntminus + i == 2) & (int(prefix[i]) == int(prefix[i+1])+1): cntminus+=1

	same += cntsame
	plus1 += cntplus
	minus1 += cntminus  * 10 ** (8 - minus1)

	quantity = [1, 10 ** (8 - plus1 + cntplus), 10 ** (8 - minus1 + cntminus)]

	vars = [same, plus1, minus1]
	leader = max(vars) 
	res = 0
	for i in range(3):
		if vars[i] == leader: res += quantity[i]
	return res

prefix = input()

print(check(prefix))

