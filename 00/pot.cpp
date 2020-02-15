#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int total = 0;
    for (int i = 0; i < N; i++)
    {
        std::string numberstr;
        cin >> numberstr;

        int lastIdx = numberstr.size()-1;
        int power = stoi(numberstr.substr(lastIdx, lastIdx+1));
        int number = stoi(numberstr.substr(0, lastIdx));

        total += pow(number, power);
    }
    cout << int(total) << endl;
    return 0;
}
