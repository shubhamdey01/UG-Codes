# Affine Cipher

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

def encode(k):
    st = input("\nEnter text to Encode :\n")
    en = ""
    for i in range(len(st)):
        x = k[0] * (ord(st[i]) - 32) + k[1]
        en += chr(x % 95 + 32)
    return en

def decode(k):
    st = input("\nEnter text to Decode :\n")
    de = ""
    for i in range(len(st)):
        x = k[0] * (ord(st[i]) - 32 - k[1])
        de += chr(x % 95 + 32)
    return de

# __main__
ch = input("1. Encode\n2. Decode\n\nEnter your choice :\t")
if ch=='1':
    k = [0, 0]
    while 1:
        k[0] = int(input("\nEnter 'a' for Encoding :\t"))
        k[1] = int(input("Enter 'b' for Encoding :\t"))
        if modInverse(k[0],95):
            break
        print("\na = ", k[0], "is relatively prime to 95.\nChoose another value of 'a'.\n")
    en = encode(k)
    print("\nEncoded text : ", en)
elif ch=='2':
    k = [0, 0]
    while 1:
        k[0] = int(input("\nEnter 'a' for Decoding :\t"))
        k[1] = int(input("Enter 'b' for Decoding :\t"))
        k[0] = modInverse(k[0],95)
        if k[0]:
            break
        print("\na = ", a, "is relatively prime to 95.\nChoose another value of 'a'.\n")
    de = decode(k)
    print("\nDecoded text : ", de)
else:
    print("\nIncorrect Choice.\nTerminating.")
