import math

# Function to calculate Euclidean distance between two points
def compute_distance(x1, y1, x2, y2):
    distance = 0
    distance=math.sqrt((x1-x2)**2+(y1-y2)**2)
    res = "{:.2f}".format(distance)
    print("Distance:",res)


if __name__ == '__main__':
    test_cases = int(input())
    while(test_cases!=0):
        x1,y1,x2,y2=input().split()
        x1=int(x1)
        x2=int(x2)
        y1=int(y1)
        y2=int(y2)
        compute_distance(x1, y1, x2, y2)
        test_cases-=1