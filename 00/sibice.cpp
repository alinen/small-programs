#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N, W, H;
    cin >> N;
    cin >> W;
    cin >> H;

    int diag = sqrt(W*W + H*H);
    for (int i = 0; i < N; i++)
    {
        int len;
        cin >> len;
        if (len <= diag) cout << "DA\n";
        else cout << "NE\n";
    }
    return 0;
}
