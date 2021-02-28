# [17141] 연구소 2 - Python

## :mag: Algorithm
**BFS, Brute-Force**

## :computer: Logic
### `BFS`

```Python
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
```
- **BFS로 바이러스를 퍼뜨리는 함수**    
  * copy_lab의 값이 ***-1*** 이면 큐에 **append**  
  * 다른 BFS 문제처럼 상하좌우 확인하면서 값이 ***0***이나 ***2***이면  
  * 값을 ***-1***로 바꿔주고 **time** 리스트를 업데이트 해주고 큐에 **append**  
  * 탐색이 끝나면 모든 빈칸에 바이러스가 퍼졌는지 확인하고  
  * 현재 상태에서 시간의 **최댓값**을 구한 후 result가 **최소**가 되는지 비교 후 바꿔준다.  
---

### `Brute-Force`  
```Python
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
```
- **바이러스를 놓기 위한 함수**  
  * lab의 값이 ***2***인 경우에 **virus** 리스트에 **append**  
  ```Python
  from itertools import combinations
  ```
  * **combinations**를 이용해서 조합 후  
  * **spreadVirus() 함수**를 호출  

## :memo: Review
[14502] 연구소 문제랑 비슷하지만  
벽을 세우는 것 대신에 바이러스를 주어진 M만큼 놓아야 함  

연구소 문제에서 pypy3로만 통과하는 방식으로 짜니까  
여기서는 통과가 안돼서  
combinations를 이용하는 방법으로 바꿨고  
그러니까 Python3로도 바로 통과함


