#include <iostream>

using namespace std;
int main(int argc, char** argv)
{
    int N;
    cin >> N;

    float total = 0;
    for (int i = 0; i < N; i++)
    {
        float val;
        cin >> val;
        total += val;
    }
    cout << total << endl;
}