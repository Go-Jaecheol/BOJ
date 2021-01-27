n = int(input())
dp = [[[0 for x in range(1024)]for y in range(10)]for z in range(n)]


for i in range(1, 10):
    dp[0][i][1<<i] = 1

for i in range(1, n):
    for j in range(10):
        for k in range(0, 1024):
            if j == 0:
                dp[i][j][k|(2**j)] = dp[i][j][k|(2**j)] + dp[i-1][j+1][k] % 1000000000
            elif j == 9:
                dp[i][j][k|(2**j)] = dp[i][j][k|(2**j)] + dp[i-1][j-1][k] % 1000000000
            else:
                dp[i][j][k|(2**j)] = dp[i][j][k|(2**j)] + (dp[i-1][j-1][k] + dp[i-1][j+1][k]) % 1000000000

result = 0
for i in range(10):
    result = (result + dp[n-1][i][1023]) % 1000000000

print(result)