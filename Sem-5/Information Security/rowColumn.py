def encrypt(p, k):
    n = len(k)
    m = (len(p)//n) if(len(p)%n == 0) else (len(p)//n + 1)
    pad = m*n - len(p)
    p += '#'*pad
    lst = []
    for i in range(m):
        lst += [[0] * n]

    x = 0
    for i in range(m):
        for j in range(n):
            lst[i][j] = p[x]
            x+=1

    c = ""
    for i in range(n):
        idx = k.index(str(i+1))
        for j in range(m):
            c += lst[j][idx]

    return c

def decrypt(c, k):
    n = len(k)
    m = len(c)//n
    lst = []
    for i in range(m):
        lst += [[0] * n]

    x = 0
    for i in range(n):
        idx = k.index(str(i+1))
        for j in range(m):
            lst[j][idx] = c[x]
            x += 1

    p = ""
    for i in range(m):
        for j in range(n):
            if i==m-1 and lst[i][j] == '#':
                break
            p += lst[i][j]

    return p

#__main__
ch = input("a. Encode\nb. Decode\n\nEnter your choice :\t")
if ch=='a':
    k = list(input("\nEnter list 'k' for Encoding :\t"))
    p = input("Enter the text :\n")
    en = encrypt(p, k)
    print("\nEncoded text : ", en)
elif ch=='b':
    k = list(input("\nEnter list 'k' for Encoding :\t"))
    c = input("Enter the text :\n")
    de = decrypt(c, k)
    print("\nDecoded text : ", de)
else:
    print("\nIncorrect Choice.\nTerminating.")


# ttnaaptmtsuoaodwcoixknlypetz
# attackpostponeduntiltwoamxyz
# 4312567
