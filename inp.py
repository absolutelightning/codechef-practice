import random

print(1)
print(int(1e5))
st = ""
for i in range(0, int(1e5)):
    st += str(random.randint(1, 10)) + " "
print(st)