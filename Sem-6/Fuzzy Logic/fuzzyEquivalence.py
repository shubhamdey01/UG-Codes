# Fuzzy Equivalence Relation

def reflexive(r,n):
    for i in range(n):
        if r[i][i] != 1.0:
            return False, "Reflexivity fails for ("+str(i)+", "+str(i)+")"
    return True, ""

def symmetric(r,n):
    for i in range(n):
        for j in range(n):
            if r[i][j] != r[j][i]:
                return False, "Symmetry fails for ("+str(i)+", "+str(j)+") and ("+str(j)+", "+str(i)+")"
    return True, ""

def transitive(r,n):
    for i in range(n):
        for j in range(n):
            for k in range(n):
                min_value = min(r[i][j], r[j][k])
                if min_value > r[i][k]:
                    return False, "Transitivity fails for ("+str(i)+", "+str(j)+") and ("+str(j)+", "+str(k)+")"
    return True, ""

def equivalence(r,n):
    ref, refR = reflexive(r,n)
    print("\nReflexivity : " + str(ref) + " ["+refR+"]\n")

    sym, symR = symmetric(r,n)
    print("Symmetry : " + str(sym) + " ["+symR+"]\n")

    tra, traR = transitive(r,n)
    print("Transitivity : " + str(tra) + " ["+traR+"]\n")

    if ref and sym and tra :
        print("Fuzzy Equivalence Relation : True")
    else :
        print("Fuzzy Equivalence Relation : False")


def display(lst,n):
    for i in range(n):
        print("\t", end="")
        for j in range(n):
            print(lst[i][j], end="  ")
        print()


#__main__
n = int(input("Enter size : "))
print("\nEnter the Relation :")
r = []
for i in range(n):
    r.append([float(j) for j in input().split(" ")])

print("\nRelation :")
display(r,n)
equivalence(r,n)


'''

OUTPUT 1 :-

Enter size : 3

Enter the Relation :
(0,0) : 1
(0,1) : 0.3
(0,2) : 0.8
(1,0) : 0.3
(1,1) : 1
(1,2) : 0.5
(2,0) : 0.8
(2,1) : 0.5
(2,2) : 1

Relation :
    1.0  0.3  0.8  
    0.3  1.0  0.5  
    0.8  0.5  1.0  

Reflexivity : True []

Symmetry : True []

Transitivity : False [Transitivity fails for (0, 2) and (2, 1)]

Fuzzy Equivalence Relation : False
================================================================

OUTPUT 2 :-

Enter size : 3

Enter the Relation :
(0,0) : 1
(0,1) : 0.3
(0,2) : 0.8
(1,0) : 0.3
(1,1) : 0.9
(1,2) : 0.5
(2,0) : 0.9
(2,1) : 0.5
(2,2) : 1

Relation :
    1.0  0.3  0.8  
    0.3  0.9  0.5  
    0.9  0.5  1.0  

Reflexivity : False [Reflexivity fails for (1, 1)]

Symmetry : False [Symmetry fails for (0, 2) and (2, 0)]

Transitivity : False [Transitivity fails for (0, 2) and (2, 1)]

Fuzzy Equivalence Relation : False
================================================================

OUTPUT 3 :-

Enter size : 3

Enter the Relation :
(0,0) : 1
(0,1) : 0.5
(0,2) : 0.8
(1,0) : 0.5
(1,1) : 1
(1,2) : 0.5
(2,0) : 0.8
(2,1) : 0.5
(2,2) : 1

Relation :
    1.0  0.5  0.8  
    0.5  1.0  0.5  
    0.8  0.5  1.0  

Reflexivity : True []

Symmetry : True []

Transitivity : True []

Fuzzy Equivalence Relation : True

'''