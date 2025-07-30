from collections import deque
import sys

dq = deque()
N = int(sys.stdin.readline())

for _ in range(N):
    command_line = sys.stdin.readline().split()

    command = command_line[0] 

    if command == "push_back":
        num = int(command_line[1])
        dq.append(num)
    elif command == "push_front":
        num = int(command_line[1])
        dq.appendleft(num)
    elif command == "pop_front":
        if (len(dq) == 0):
            print(-1)
        else:
            print(dq.popleft())
    elif command == "pop_back":
        if (len(dq) == 0):
            print(-1)
        else:
            print(dq.pop())
    elif command == "size":
        print(len(dq))
    elif command == "empty":
        if (len(dq) == 0):
            print(1)
        else:
            print(0)
    elif command == "front":
        if (len(dq) == 0):
            print(-1)
        else:
            print(dq[0])
    elif command == "back":
        if (len(dq) == 0):
            print(-1)
        else:
            print(dq[-1])