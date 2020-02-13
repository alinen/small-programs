#include <iostream>
#include <map>

using namespace std;
int main()
{
    map<char, int> counts;
    for (int i = 0; i < 5; i++)
    {
        string hand;
        cin >> hand;

        if (counts.find(hand[0]) == counts.end())
        {
            counts[hand[0]] = 0;
        }
        counts[hand[0]]++;
    }

    int maxCount = 0;
    for (auto it = counts.begin(); it != counts.end(); ++it)
    {
        maxCount = max(maxCount, it->second);
    }

    cout << maxCount << endl;
}
