n = int(input())
house = [[int(x) for x in input().split()]for y in range(n)]
dp = [[0 for x in range(n)]for y in range(n)]

for i in range(3):
    dp[0][i] = house[0][i]

for i in range(1, n):
    for j in range(3):
        if j == 0:
            dp[i][j] = min(dp[i-1][1]+house[i][j], dp[i-1][2]+house[i][j])
        elif j == 1:
            dp[i][j] = min(dp[i-1][0]+house[i][j], dp[i-1][2]+house[i][j])
        elif j == 2:
            dp[i][j] = min(dp[i-1][0]+house[i][j], dp[i-1][1]+house[i][j])

print(min(dp[n-1][0],dp[n-1][1],dp[n-1][2]))