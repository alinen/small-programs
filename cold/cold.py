# python ../submit.py -p cold cold.py -l "Python 3"
import sys

n = int(input())
count = 0
line = input()
for token in line.split():
    v = int(token)
    if v < 0:
        count = count + 1
print(count)

