# python ../submit.py -p cold cold.py -l "Python 3"
import sys

n = int(input())
print(n, file=sys.stderr)
line = input()
count = 0
for token in line.split():
    v = int(token)
    print(v, file=sys.stderr)
    if v < 0:
        count = count + 1
print(count)

