# Rail-Fence Cipher

def encode(h=2):
    st = input("\nEnter text to Encode :\n")
    lst = [['\t' for i in range(len(st))] for j in range(h)]
    flag = False
    x = 0
    for i in range(len(st)):
        if x == 0 or x == h-1:
            flag = not flag
        lst[x][i] = st[i]
        if flag:
            x += 1
        else:
            x -= 1
    en = ""
    z = x = 0
    for i in range(h):
        for j in range(len(st)):
            if lst[i][j] != '\t':
                en += lst[i][j]
    return en

def decode(h=2):
    st = input("\nEnter text to decode :\n")
    lst = [['\t' for i in range(len(st))] for j in range(h)]
    flag = True
    z = x = 0
    y = h - 1
    for i in range(len(st)):
        if z >= len(st):
            flag = True
            x += 1
            z = x
        # print(x,z,i, flag)
        lst[x][z] = st[i]
        if flag:
            z += 2*abs(x-y) if x-y!=0 else 2*x
        else:
            z += 2*x if x!=0 else 2*y
        flag = not flag
    de = ""
    for i in range(len(st)):
        for j in range(h):
            if lst[j][i] != '\t':
                de += lst[j][i]
    return de

# __main__
ch = input("a. Encode\nb. Decode\n\nEnter your choice :\t")
if ch == 'a':
    h = int(input("Enter height for encoding :\t"))
    en = encode(h) if h>1 else encode()
    print("Encoded text :\t", en)
elif ch == 'b':
    h = int(input("Enter height for decoding :\t"))
    de = decode(h) if h > 1 else decode()
    print("Decoded text :\t", de)
else:
    print("Invalid Choice.\nTerminating.")