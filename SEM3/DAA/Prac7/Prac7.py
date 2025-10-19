def Optimal_bst(p,q,n):
    e = [[0]*(n+2) for i in range(n+2)]
    w = [[0]*(n+2) for i in range(n+2)]

    for i in range(1, n+2):
        e[i][i-1] = q[i-1]
        w[i][i-1] = q[i-1]

    for l in range(1, n+1):
        for i in range(1, n-l+2):
            j = i + l - 1
            e[i][j] = float('inf')
            w[i][j] = w[i][j-1] + p[j-1] + q[j]
            for r in range(i, j+1):
                cost = e[i][r-1] + e[r+1][j] + w[i][j]
                if cost < e[i][j]:
                    e[i][j] = cost

    return e[1][n]

n = int(input())
keys = list(map(int, input().split()))
p = list(map(float, input().split()))
q = list(map(float, input().split()))

min_cost = Optimal_bst(p, q, n)
print(f"{min_cost:.4f}")
