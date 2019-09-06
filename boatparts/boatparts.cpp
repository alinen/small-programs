#include <fstream>
#include <iostream>
#include <map>

using namespace std;
int main()
{
    int N = 0;
    int P = 0;
    cin >> P;
    cin >> N;
    map<string,bool> parts;
    for (int i = 0; i < N; i++)
    {
        string part;
        cin >> part;
        parts[part] = true;
        if (parts.size() == P)
        {
            cout << i+1 << endl;        
            return 0;
        } 
    }
    cout << "paradox avoided" << endl;
    return 0;
}