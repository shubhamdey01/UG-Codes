# Hill cipher (Encryption 3x3)

def encrypt(p, k):
    p = p.replace(" ", "")
    pad = len(p) % 3
    p += "#"*pad
    lst = []
    m = len(p)//3
    for i in range(m):
        lst += [[0] * 3]
    x = 0
    for i in range(m):
        for j in range(3):
            y = p[x].upper()
            lst[i][j] = ord(y) - 65
            x += 1
    mat = matMultiply(lst, k)
    c = ""
    for i in range(m):
        for j in range(3):
            y = chr(mat[i][j]%26 + 65)
            c += y
    return c

def getMatrix():
    m = []
    for i in range(3):
        a = input().split(" ")
        m.append(a)
    for i in range(3):
        for j in range(3):
            m[i][j] = int(m[i][j])
    return m

def matMultiply(a, b):
    c = []
    for i in range(len(a)):
        c += [[0] * 3]
    for i in range(len(a)):
        for j in range(3):
            for k in range(3):
                c[i][j] += a[i][k]*b[k][j]
    return c

#__main__
print("Enter 3x3 key matrix")
k = getMatrix()
p = input("Enter plaintext :\n")
en = encrypt(p, k)
print("\nEncoded text : ", en)


# 17 17 5
# 21 18 21
# 2 2 19

# paymoremoney
# RRLMWBKASPDH