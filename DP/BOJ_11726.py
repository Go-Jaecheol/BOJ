import sys
sys.setrecursionlimit(10**6)

n = int(input())
memo = [0 for i in range(1001)]

def dp(n):
    if memo[n] > 0:
        return memo[n]
    if n <= 2:
        memo[n] = n
        return memo[n]
    else:
        memo[n] = dp(n-1) + dp(n-2)
        return memo[n]

print(dp(n)%10007)