# [7662] 이중 우선순위 큐 - Python

## :mag: Algorithm
**Priority Queue**

## :computer: Logic

```Python
if operation == 'I':
  exist[i] = True
  heapq.heappush(min_q, (num, i))
  heapq.heappush(max_q, (-num, i))
```
- **연산이 I 일 경우**    
  * `min_q`와 `max_q` 둘 다 **heappush**  
  * `exist[i]` 값을 ***True***로 변경  
---
```Python
else:
  if num == -1:
    while min_q and not exist[min_q[0][1]]:
      heapq.heappop(min_q)
    if min_q:
      exist[min_q[0][1]] = False
      heapq.heappop(min_q)
  else:
    while max_q and not exist[max_q[0][1]]:
      heapq.heappop(max_q)
    if max_q:
      exist[max_q[0][1]] = False
      heapq.heappop(max_q)
```
- **연산이 D 일 경우**  
  * 삭제할 값이 `min_q`, `max_q` 둘다에 존재하는지 `exist`값을 통해 확인하고  
  * 존재 안하면 존재할 때까지 **heappop**  
  * 그 다음 삭제할 값의 `exist` 값을 ***False***로 바꿔주고 **heappop**  
  * 이 과정은 `num`이 ***-1***이면 `min_q`를, `num`이 ***1***이면 `max_q`를 대상으로 진행  
---
```Python
while min_q and not exist[min_q[0][1]]:
  heapq.heappop(min_q)
while max_q and not exist[max_q[0][1]]:
  heapq.heappop(max_q)
if not max_q:
  print('EMPTY')
else:
  print(-max_q[0][0], min_q[0][0])
```
- **출력하는 부분**  
  * 혹시나 **동기화**가 안됐을 경우를 대비해서  
  * 위에서 했던 **첫번째 과정**을 다시 실행하고  
  * `max_q`에 값이 없으면 ***'EMPTY'*** 출력  
  * 아니면 **최댓값**과 **최솟값**을 출력  
---

## :memo: Review
처음에는 그냥 우선순위 큐를 이용해서  
최소 힙, 최대 힙 둘 다 한번에 할 수 있도록만  
하면 되는 줄 알고 쉽게 봤었는데  
역시나 바로 시간초과가 났다.

그 다음에는 인덱스를 같이 넣어줘서  
exist 리스트를 통해 최소 힙과 최대 힙 두 개를  
서로 동기화 하는 방법을 알아냈지만  
계속 통과를 못했다,,

이유는 출력할 때 최댓값을 `-max_q[0][0]`이 아닌 `abs(max_q[0][0])`으로 해서 였는데  
이유를 알고 처음에는 왜 이거 때문에 오답이였는지 이해 못하다가  
잠들기 직전에 최댓값도 음수일 수 있다는 생각을 해서 알아차렸다. 하ㅏㅏ

앞으로는 모든 케이스 다 확인하고 통과화기 전에는 확신하지 말자
