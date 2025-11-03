import sys
input = sys.stdin.readline

T = int(input())
for i in range(T):
    n = int(input())
    s,t = map(int, input().split()) 
    answer = 0
    while n > 0:
        if n % 2 != 0:
            n -= 1
            answer += s
        else:
            n //= 2
            answer += min(n*s,t)
    print(answer)