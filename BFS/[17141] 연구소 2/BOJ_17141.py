from collections import deque
from itertools import combinations

N, M = map(int, input().split())
lab = [[int(x) for x in input().split()]for y in range(N)]
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
MAX_SIZE = 50*50+1
result = MAX_SIZE

def spreadVirus(copy_lab):
    global result
    
    time = [[0 for x in range(N)]for y in range(N)]
    que = deque()

    for i in range(N):
        for j in range(N):
            if copy_lab[i][j] == -1:
                que.append((i, j))
    while que:
        y, x = que.popleft()
        for k in range(4):
            next_x = x + dx[k]
            next_y = y + dy[k]
            if 0 <= next_x < N and 0 <= next_y < N:
                if copy_lab[next_y][next_x] == 0 or copy_lab[next_y][next_x] == 2:
                    copy_lab[next_y][next_x] = -1
                    time[next_y][next_x] = time[y][x] + 1
                    que.append((next_y, next_x))

    for i in range(N):
        for j in range(N):
            if copy_lab[i][j] == 0 or copy_lab[i][j] == 2:
                return
    
    max_time = max(map(max, time))
    result = min(result, max_time)

def putVirus(count):
    virus = []
    for i in range(N):
        for j in range(N):
            if lab[i][j] == 2:
                virus.append((i, j))
    comb = list(combinations(virus, M))
    for c in comb:
        copy_lab = [lab[i][:] for i in range(N)]
        for i in range(M):
            copy_lab[c[i][0]][c[i][1]] = -1
        spreadVirus(copy_lab)

putVirus(0)
if result == MAX_SIZE:
    print(-1)
else:
    print(result)