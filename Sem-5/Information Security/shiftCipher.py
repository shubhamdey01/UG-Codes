# Shift Cipher
# k=3 => Ceaser Cipher

def encode(k=3):
    str = input("\nEnter text to Encode :\n")
    en = ""
    for i in range(0, len(str)):
        x = ord(str[i]) - 32
        y = (x + k) % 95
        en += chr(y + 32)
    return en

def decode(k=3):
    str = input("\nEnter text to Decode :\n")
    de = ""
    for i in range(0, len(str)):
        x = ord(str[i]) - 32
        y = (x - k) % 95
        de += chr(y + 32)
    return de

# __main__
ch = input("a. Encode\nb. Decode\n\nEnter your choice :\t")
if ch=='a':
    k = int(input("\nEnter 'k' for Encoding :\t"))
    en = encode(k) if k>0 else encode()
    print("\nEncoded text : ", en)
elif ch=='b':
    k = int(input("\nEnter 'k' for Encoding :\t"))
    de = decode(k) if k>0 else decode()
    print("\nDecoded text : ", de)
else:
    print("\nIncorrect Choice.\nTerminating.")
