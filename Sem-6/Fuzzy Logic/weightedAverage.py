# Defuzzification : Weighted Average

def weightedAvg(s):
	mul = 0; deg = 0
	for i in range(len(s)):
		lst = list(s[i].keys())
		avg = sum(lst)/len(lst)
		for j in range(len(lst)-1):
			if lst[j] <= avg <= lst[j+1]:
				y = yVal(avg,lst[j+1],s[i][lst[j+1]],lst[j],s[i][lst[j]])
		mul += avg * y
		deg += y
	return mul/deg

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

res = weightedAvg(sets)
print("Defuzzified value = ", res)