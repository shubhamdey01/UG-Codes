# Defuzzification : Centroid Method

def centroid(s):
	x = {}
	for i in range(len(s)):
		for j in s[i].keys():
			if j in x.keys():
				x[j] = max(x[j], s[i][j])
			else:
				x[j] = s[i][j]

	v = list(x.keys())
	d = list(x.values())
	I = 0.08; ar = 0; aXb = 0

	for i in range(len(v)-1):
		x1 = v[i]
		while x1 < v[i+1]:
			x2 = x1 + I
			ca = I*(yVal(x1,v[i+1],d[i+1],v[i],d[i]) + yVal(x2,v[i+1],d[i+1],v[i],d[i]))/2
			ar += ca
			aXb += ca*(x1+x2)/2
			x1 += I
	return aXb/ar

def yVal(x, x2, y2, x1 ,y1):
	m = float(y2-y1)/(x2-x1)
	b = y2 - x2 * m
	return (x*m+b)

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

res = centroid(sets)
print("Defuzzified value = ", res)