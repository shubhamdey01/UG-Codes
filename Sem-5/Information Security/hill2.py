# Hill cipher (Encryption-Decryption 2x2)

import numpy as np

def encrypt(p, k):
    p = p.replace(" ", "")
    pad = len(p) % 2
    p += "#"*pad
    lst = []
    m = len(p)//2
    for i in range(m):
        lst += [[0] * 2]
    x = 0
    for i in range(m):
        for j in range(2):
            y = p[x].upper()
            lst[i][j] = ord(y) - 65
            x += 1
    mat = matMultiply(lst, k)
    c = ""
    for i in range(m):
        for j in range(2):
            y = chr(mat[i][j]%26 + 65)
            c += y
    return c

def decrypt(c, k):
    det = k[0][0] * k[1][1] - k[0][1] * k[1][0]
    det = det % 26
    detInv = modInverse(det, 26)

    kInv = k
    kInv[0][0], kInv[1][1] = kInv[1][1], kInv[0][0]
    kInv[0][1] *= -1
    kInv[1][0] *= -1
    for i in range(2):
        for j in range(2):
            kInv[i][j] *= detInv
            kInv[i][j] = kInv[i][j] % 26

    lst = []
    m = len(c) // 2
    for i in range(m):
        lst += [[0] * 2]
    x = 0
    for i in range(m):
        for j in range(2):
            y = c[x].upper()
            lst[i][j] = ord(y) - 65
            x += 1
    mat = matMultiply(lst, kInv)
    p = ""
    for i in range(m):
        for j in range(2):
            y = chr(mat[i][j] % 26 + 65)
            p += y
    return p

def extendedEuclid(a, b):
    x,y, u,v = 0,1, 1,0
    while a != 0:
        q, r = b//a, b%a
        m, n = x-u*q, y-v*q
        b,a, x,y, u,v = a,r, u,v, m,n
        gcd = b
    return gcd, x, y

def modInverse(a, m):
    gcd, x, y = extendedEuclid(a, m)
    if gcd != 1:
        return 0
    else:
        return x % m

def matMultiply(a, b):
    c = []
    for i in range(len(a)):
        c += [[0] * 2]
    for i in range(len(a)):
        for j in range(2):
            for k in range(2):
                c[i][j] += a[i][k]*b[k][j]
    return c

def getMatrix():
    m = []
    for i in range(2):
        a = input().split(" ")
        m.append(a)
    for i in range(2):
        for j in range(2):
            m[i][j] = int(m[i][j])
    return m

# __main__
ch = input("a. Encode\nb. Decode\n\nEnter your choice :\t")
if ch == 'a':
    print("Enter 2x2 key matrix")
    k = getMatrix()
    p = input("Enter plaintext :\n")
    en = encrypt(p, k)
    print("\nEncoded text : ", en)
elif ch == 'b':
    print("Enter 2x2 key matrix")
    k = getMatrix()
    c = input("Enter ciphertext :\n")
    de = decrypt(c, k)
    print("\nDecoded text : ", de)
else:
    print("\nIncorrect Choice.\nTerminating.")

# 17 17 5
# 21 18 21
# 2 2 19

# paymoremoney
# RRLMWBKASPDH