from math import ceil
def minimax(array):
    length=len(array)
    if len(array)==0:return 9999,-9999
    if len(array)==1:return (array[0],array[0])
    minmax1=minimax(array[0:ceil(length/2)])
    minmax2=minimax(array[ceil(length/2):length])
    return min(minmax1[0],minmax2[0]),max(minmax1[1],minmax2[1])

print(minimax([4,3,5,4,6,4,-2,4]))