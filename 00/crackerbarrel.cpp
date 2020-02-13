#include <fstream>
#include <iostream>
#include <map>

using namespace std;

enum Dir {NW, W, SW, SE, E, NE};
int graph[15][6] = 
{
    {-1, -1,  1,  2, -1, -1},  // 0
    {-1, -1,  3,  4,  2,  0},  // 1
    { 0,  1,  4,  5, -1, -1},  // 2
    {-1, -1,  6,  7,  4,  1},  // 3
    { 1,  3,  7,  8,  5,  2},  // 4
    { 2,  4,  8,  9, -1, -1},  // 5
    {-1, -1, 10, 11,  7,  3},  // 6
    { 3,  6, 11, 12,  8,  4},  // 7
    { 4,  7, 12, 13,  9,  5},  // 8
    { 5,  8, 13, 14, -1, -1},  // 9
    {-1, -1, -1, -1, 11,  6},  // 10
    { 6, 10, -1, -1, 12,  7},  // 11
    { 7, 11, -1, -1, 13,  8},  // 12
    { 8, 12, -1, -1, 14,  9},  // 13
    { 9, 13, -1, -1, -1, -1}  // 14
};

bool evalBoard(const string& board, char winSym)
{
    // check success
    // if one peg on the board and it's the desired sym, return true
    map<char,int> counts;
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i] != '_')
        {
            if (counts.find(board[i]) == counts.end())
            {
                counts[board[i]] = 0;
            }
            counts[board[i]]++;
        } 
    }
    if (counts.find(winSym) == counts.end()) return false; // sym not found
    else if (counts.size() == 1 && counts[winSym] == 1) return true; // we win!
    // else look for more boards

    bool success = false;
    for (int i = 0; i < board.size() && !success; i++)
    {
        char sym = board[i];
        if (sym == '_') continue;

        for (int m = 0; m < 6 && !success; m++)
        {
            // if neighbor is not empty 
            // AND neighbors straight-line neighbor is not empty
            // -> valid move. Try it and see what happens
            int idx = graph[i][m];
            if (idx != -1 && board[idx] != '_')
            {
                int nidx = graph[idx][m];
                if (nidx != -1 && board[nidx] == '_')
                {
                    string newboard = board;
                    //cerr << "moving peg " << sym << " from " << i << " to " << nidx << " (removes " << board[idx] << " at " << idx << ")" << endl;
                    newboard[i] = '_'; // jump peg from i to nidx and remove peg at idx
                    newboard[idx] = '_'; // remove peg
                    newboard[nidx] = sym;
                    //cerr << "apply move " << board << " -> " << newboard << endl;

                    success = evalBoard(newboard, winSym);
                }
            }
        }
    }
    return success;
}

int main()
{
    string line;
    cin >> line;
    char winSym = line[0];

    while (line != "**")
    {
        string board;
        for (int i = 0; i < 5; i++)
        {
            cin >> line;
            for (int j = 0; j < line.size(); j+=2)
            {
                board += line[j];
            }
        }
        cerr << board << endl;
        bool canDo = evalBoard(board, winSym);
        if (canDo) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
        cin >> line;
        winSym = line[0];
    }
    return 0;
}