S = input("enter your student name - ")
R = input("enter roll number - ")
m1 = int(input("enter maths marks - "))
m2 = int(input("enter english marks - "))
m3 = int(input("enter science marks - "))

if m1 > m2 and m1 > m3:
    print("m1 has highest marks")
elif m2 > m1 and m2 > m3:
    print("m2 has highest marks")
else:
    print("m3 has highest marks")

if m1 < m2 and m1 < m3:
    print("m1 is lowest")
elif m2 < m1 and m2 < m3:
    print("m2 is lowest")
else:
    print("m3 is lowest")

P = (m1 + m2 + m3) / 3
print("percentage is ", P, "%")
