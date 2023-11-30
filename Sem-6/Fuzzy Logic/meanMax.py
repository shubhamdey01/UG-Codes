# Defuzzification : Mean-Max Membership

def meanMax(s):
	x = {}
	for i in range(len(s)):
		for j in s[i].keys():
			if j in x.keys():
				x[j] = max(x[j], s[i][j])
			else:
				x[j] = s[i][j]
	res = []
	for i in x.keys():
		if x[i] == max(x.values()):
			res.append(i)
	return (max(res)+min(res))/2

#__main__
n = int(input("Enter the no. of fuzzy sets :\t"))
sets = []

for i in range(n):
	val = [float(j) for j in input("Enter set-"+str(i)+" :\n").split(" ")]
	deg = [float(j) for j in input("Enter degree for set-"+str(i)+" :\n").split(" ")]
	assert(len(val) == len(deg))
	temp = {}
	for j in range(len(val)):
		temp[val[j]] = deg[j]
	sets.append(temp)

res = meanMax(sets)
print("Defuzzified value = ", res)