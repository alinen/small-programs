# python submit.py datum.py -l "Python 3"
import datetime;

values = input()
D,M = values.split()
D = int(D)
M = int(M)

names = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
dt = datetime.date(2009, M, D)
print(names[dt.weekday()])
