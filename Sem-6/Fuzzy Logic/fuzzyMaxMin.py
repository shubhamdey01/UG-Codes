# Fuzzy Composition using Max-Min

def maxMin(r1, r2):
    m = len(r1)
    n = len(r1[0])
    o = len(r2[0])
    
    lst = [[0 for i in range(o)] for j in range(m)]
    for i in range(m):
        for j in range(o): 
            temp = []
            for k in range(n):
                temp.append(min(r1[i][k],r2[k][j]))
            lst[i][j] = max(temp)
    
    return lst

def display(lst):
    m = len(lst)
    n = len(lst[0])
    for i in range(m):
        for j in range(n):
            print(lst[i][j], end="  ")
        print()

#__main__
Xn = int(input("No. of elements in universe X :\t"))
Yn = int(input("No. of elements in universe Y :\t"))
Zn = int(input("No. of elements in universe Z :\t"))

R = []
S = []

print("\nEnter degree of belonging for relation R(X,Y) :")
for i in range(Xn):
    R.append([float(j) for j in input().split(" ")])

print("\nEnter degree of belonging for relation S(Y,Z) :")
for i in range(Yn):
    S.append([float(j) for j in input().split(" ")])

T = maxMin(R, S)

print("\nRelation R(X,Y) :")
display(R)
print("\nRelation S(Y,Z) :")
display(S)
print("\nComposition T(X,Z) :")
display(T)


'''
OUTPUT :-

No. of elements in universe X : 2
No. of elements in universe Y : 2
No. of elements in universe Z : 3

Enter degree of belonging for relation R(X,Y) :
(x0, y0) = 0.7
(x0, y1) = 0.5
(x1, y0) = 0.8
(x1, y1) = 0.4

Enter degree of belonging for relation S(Y,Z) :
(y0, z0) = 0.9
(y0, z1) = 0.6
(y0, z2) = 0.2
(y1, z0) = 0.1
(y1, z1) = 0.7
(y1, z2) = 0.5

Relation R(X,Y) :
0.7  0.5  
0.8  0.4  

Relation S(Y,Z) :
0.9  0.6  0.2  
0.1  0.7  0.5  

Composition T(X,Z) :
0.7  0.6  0.5  
0.8  0.6  0.4 

'''