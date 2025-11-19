from sys import stdin
input = stdin.readline

N, M, q = map(int, input().split())
matrix = [[0]*M]*N
for i in range(N):
    matrix[i] = list(map(int, input().split()))
for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 0:
        matrix[query[1]][query[2]] = query[3]
    elif query[0] == 1:
        matrix[query[1]], matrix[query[2]] = matrix[query[2]], matrix[query[1]]
for i in range(N):
    row = map(str, matrix[i])
    print(" ".join(row))