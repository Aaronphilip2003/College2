def flip(num):
    if num==0:
        return 1
    else:
        return 0

list=[]
for i in range(0,200):
    list.append(0)

print(list)

for i in range(0,200):
    if list[i]==0:
        list[i]=1
        
print(list)

for i in range(2,200):
    for j in range(0,200,i):
        if list[j]==0:
            list[i]=flip(j)
        elif list[j]==1:
            list[i]=flip(j)

print(list)