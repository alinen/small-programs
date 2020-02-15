#include <iostream>
using namespace std;

int main()
{
    int H, M;
    cin >> H;
    cin >> M;

    int dayMins = 24 * 60;
    int wakeUpMins = (H * 60 + M - 45 + dayMins) % dayMins;
    
    int newH = int(wakeUpMins/60);
    int newM = int(wakeUpMins % 60);
    cout << newH << " " << newM << endl;
    return 0;
}