# Crisp Equivalence Relation

def reflexive(r,n):
    for i in range(n):
        if r[i][i] != 1:
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
    r.append([int(j) for j in input().split(" ")])

print("\nRelation :")
display(r,n)
equivalence(r,n)