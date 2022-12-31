dn=int(input("Enter the decimal number:"))
bn=0 #to store the binary number
i=0
while(dn!=0):
    d=dn%2
    bn=bn+d*(10**i)
    i+=1
    dn//=2

print("Binary number=",bn)