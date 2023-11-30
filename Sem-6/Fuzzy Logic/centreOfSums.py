# Defuzzification : Centre of Sums

def centreOfSums(s):
	num = 0; deno = 0
	for i in range(len(s)):
		v = list(s[i].keys())
		d = list(s[i].values())
		a = 0
		for j in range(len(v)-1):
			a += area(v[j],d[j],v[j+1],d[j+1])
		num += a * (sum(v)/len(v))
		deno += a

	return num/deno

def area(v1, d1, v2, d2):
	I = 0.08; a = 0
	x1 = v1
	while x1 < v2:
		x2 = x1 + I
		ca = I*(yVal(x1,v2,d2,v1,d1) + yVal(x2,v2,d2,v1,d1))/2
		a += ca
		x1 += I
	return a

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

res = centreOfSums(sets)
print("Defuzzified value = ", res)