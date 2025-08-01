n = int(input())
dp = {}
def f(n):
    if n <= 2:
        return 1
    if n in dp:
        return dp[n]
    dp[n] = f(n - 1) + f(n - 2)
    return dp[n]
print(f(n))