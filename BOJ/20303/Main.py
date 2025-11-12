import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())
candy = list(map(int, input().split()))

parent = list(range(N))
rank = [0] * N
size = [1] * N

def find(x):
    while parent[x] != x:
        parent[x] = parent[parent[x]]
        x = parent[x]
    return x

def union(a, b):
    a = find(a)
    b = find(b)
    if(a == b):
        return
    if(rank[a] < rank[b]):
        a, b = b, a
    parent[b] = a
    size[a] += size[b]
    if(rank[a] == rank[b]):
        rank[a] += 1

for _ in range(M):
    a, b = map(int, input().split())
    union(a - 1, b - 1)

candy_sum = {}
kid_sum = {}

for i in range(N):
    j = find(i)
    candy_sum[j] = candy_sum.get(j, 0) + candy[i]
    kid_sum[j] = kid_sum.get(j, 0) + 1
    # j가 있으면 j의 값을 가져오고 디폴트는 0으로 유지

if K == 1:
    print(0)
    sys.exit(0)

steal = K - 1
dp = [0] * K

for root, weight in kid_sum.items(): # root 별로 몇 명이 들어있는지 dict로 가져오기.
    value = candy_sum[root]
    if weight > steal: continue
    for i in range(steal, weight - 1, -1):
        val = dp[i - weight] + value # 이 그룹을 추가했을 때 얻는 새로운 값
        # i - weight : 이 그룹을 추가하기 전 상태
        if val > dp[i]: # 그게 지금까지 dp보다 크면 그걸 최신화하자.
            dp[i] = val

print(max(dp))