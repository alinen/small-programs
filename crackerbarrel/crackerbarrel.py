import sys

def evalBoard(board, winSym):
    return True

def main():
    line = input()
    line = line.strip()
    winSym = line[0]

    while line != "**":
        board = ""
        for i in range(5):
            line = input().strip()
            for j in range(0, len(line), 2):
                board += line[j]

        print(board, len(board), file = sys.stderr)
        canDo = evalBoard(board, winSym)
        if canDo: print("Possible")
        else: print("Impossible")
        line = input()
        winSym = line[0]

main()