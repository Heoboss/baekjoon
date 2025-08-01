N = int(input())
array = []
for _ in range(N):
    array.append(int(input()))
for i in range(0,N-1):
    for j in range (1,N-i):
        if array[j-1] > array[j]:
            tmp = array[j-1]
            array[j-1] = array[j]
            array[j] = tmp
    #print(f"step{i+1} : {array}")
#print(f"오름차순 정렬 후 : {array}")
for i in range(0,N):
    print(array[i])