x = list()
y = list()
for i in range(3):
    a, b = map(int, input().split())
    if(x.count(a) == 0):
        x.append(a)
    else: 
        x.remove(a)
    if(y.count(b) == 0):
        y.append(b),
    else:
        y.remove(b)
print(x[0], y[0])