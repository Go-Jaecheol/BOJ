n = int(input())
triangle = [[int(x) for x in input().split()]for y in range(n)]
dp = [[0 for x in range(501)]for y in range(501)]

dp[0][0] = triangle[0][0]
for i in range(1, n):
    for j in range(i+1):
        if (j == 0):
            dp[i][j] = dp[i-1][0] + triangle[i][0]
        elif (j == i):
            dp[i][j] = dp[i-1][j-1] + triangle[i][j]
        else:
            dp[i][j] = max(dp[i-1][j-1]+triangle[i][j], dp[i-1][j]+triangle[i][j])

print(max(dp[n-1]))