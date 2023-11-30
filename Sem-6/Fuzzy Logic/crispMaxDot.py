# Crisp Composition using Max-Dot

def maxDot(r1, r2):
    m = len(r1)
    n = len(r1[0])
    o = len(r2[0])
    
    lst = [[0 for i in range(o)] for j in range(m)]
    for i in range(m):
        for j in range(o): 
            temp = []
            for k in range(n):
                temp.append(r1[i][k] * r2[k][j])
            lst[i][j] = max(temp)
    
    return lst

def display(lst):
    m = len(lst)
    n = len(lst[0])
    for i in range(m):
        for j in range(n):
            print(round(lst[i][j],2), end="  ")
        print()

#__main__
Xn = int(input("No. of elements in universe X :\t"))
Yn = int(input("No. of elements in universe Y :\t"))
Zn = int(input("No. of elements in universe Z :\t"))

R = []
S = []

print("\nEnter degree of belonging for relation R(X,Y) :")
for i in range(Xn):
    R.append([int(j) for j in input().split(" ")])

print("\nEnter degree of belonging for relation S(Y,Z) :")
for i in range(Yn):
    S.append([int(j) for j in input().split(" ")])

T = maxDot(R, S)

print("\nRelation R(X,Y) :")
display(R)
print("\nRelation S(Y,Z) :")
display(S)
print("\nComposition T(X,Z) :")
display(T)


'''
OUTPUT :-

No. of elements in universe X : 3
No. of elements in universe Y : 4
No. of elements in universe Z : 2

Enter degree of belonging for relation R(X,Y) :
(x0, y0) = 1
(x0, y1) = 0
(x0, y2) = 1
(x0, y3) = 0
(x1, y0) = 0
(x1, y1) = 0
(x1, y2) = 0
(x1, y3) = 1
(x2, y0) = 0
(x2, y1) = 0
(x2, y2) = 0
(x2, y3) = 0

Enter degree of belonging for relation S(Y,Z) :
(y0, z0) = 0
(y0, z1) = 1
(y1, z0) = 0
(y1, z1) = 0
(y2, z0) = 0
(y2, z1) = 1
(y3, z0) = 0
(y3, z1) = 0

Relation R(X,Y) :
1  0  1  0  
0  0  0  1  
0  0  0  0  

Relation S(Y,Z) :
0  1  
0  0  
0  1  
0  0  

Composition T(X,Z) :
0  1  
0  0  
0  0 

'''