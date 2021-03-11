import sys, heapq

N = int(sys.stdin.readline())
info = [int(sys.stdin.readline()) for x in range(N)]
h = []

def caculate(num):
    if num == 0:
        if len(h) == 0:
            print(0)
        else:
            print(heapq.heappop(h)[1])
    else:
        heapq.heappush(h, (-num, num))

for i in range(N):
    caculate(info[i])