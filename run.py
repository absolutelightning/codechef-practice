import os

single = os.getenv('SINGLE')
if single == '1':
    os.system("g++ main.cpp -w -o main")
    os.system('./main < input > out')
else:
    while True:
        os.system('g++ main.cpp -w -o main')
        os.system('g++ brute.cpp -w -o brute')
        os.system('python inp.py > input')
        os.system('./brute < input > ac')
        os.system('./main < input > wa')
        os.system('diff ac wa > diff.txt')
        size = os.stat('diff.txt').st_size
        if size == 0:
            print('ok')
            continue
        break
