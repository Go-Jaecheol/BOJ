import heapq

N = int(input())
info = [int(input()) for x in range(N)]
h = []

def caculate(num):
    if num == 0:
        if len(h) == 0:
            print(0)
        else:
            print(heapq.heappop(h))
    else:
        heapq.heappush(h, num)

for i in range(N):
    caculate(info[i])