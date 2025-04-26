A = int(input())
for i in range(A):
    B, C = input().split()
    D = int(B)
    for char in C:
        print(char*D, end='')
    print()