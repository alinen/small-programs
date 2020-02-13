import math

def decode(m):
    # m should always be a square
    N = int(math.sqrt(len(m)))
    msg = ["x" for i in range(len(m))]
    for idx in range(len(m)):
        i = int(idx/N)
        j = idx % N
        newi = N - j - 1
        newj = i
        newidx = newi * N + newj
        #print(idx, i, j, "->", newidx, newi, newj)
        msg[newidx] = m[idx]

    return "".join(msg)


def main():
    N = int(input())
    for i in range(N):
        msg = input()
        dmsg = decode(msg)
        print(dmsg)

main()