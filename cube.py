numbers=[]
print("Enter 5 numbers:")
for i in range(0,5):
    num=input()
    num=int(num)
    numbers.append(num)

print("CUBES:")

for i in range(len(numbers)):
    print(numbers[i]**3)
