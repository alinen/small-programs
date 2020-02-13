#include <iostream>
#include <map>
using namespace std;

typedef string (*Fn)(const string& state, int i);

static char rotate(char c)
{
    return (((c - 'A') + 1) % 6) + 'A';
}

static string A(const string& state, int i)
{
    int left = i-1;
    int right = i+1;

    string newstate = state;
    if (left >= 0)
    {
        char leftC = state[left];
        char leftN = rotate(leftC);
        newstate[left] = leftN;
    }

    if (right < state.size()-1)
    {
        char rightC = state[right];
        char rightN = rotate(rightC);
        newstate[right] = rightN;
    }
    return newstate;
}

static string B(const string& state, int i)
{
    if (i == 0 || i == state.size()-1) return state;

    int left = i-1;
    int right = i+1;

    string newstate = state;
    newstate[right] = state[left];
    return newstate;
}

static string C(const string& state, int i)
{
    int idx 
}
static string D(const string& state, int i)
{
}
static string E(const string& state, int i)
{
}
static string F(const string& state, int i)
{
}

map<char,Fn> moves = map<char,Fn>
{
    {'A', A},
    {'B', B},
    {'C', C},
    {'D', D},
    {'E', E},
    {'F', F},
};

int doMove(const string& state, const string& desiredState, int count)
{
    if (state == desiredState)
    {
        return count;
    }

    int minCount = 1000000;
    for (unsigned int i = 0; i < state.size(); i++)
    {
        string newstate = moves[state[i]](state, i);
        minCount = min(minCount, doMove(newstate, desiredState, count+1));
    }
    return minCount;
}

int main()
{
    string start, end;
    cin >> start;
    cin >> end;

    cout << A(start, 0) << endl;
    cout << A(start, 1) << endl;
    cout << A(start, 7) << endl;
    //int count = doMove(start, end, 0);
}
