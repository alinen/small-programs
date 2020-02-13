#include <iostream>
#include <list>
#include <map>

using namespace std;
int main()
{
    int N, M;
    cin >> N;
    cin >> M;

    int maxsum = 0;
    int maxcount = 0;
    map<int,int> sums;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            int sum = i+j;
            if (sums.find(sum) == sums.end())
            {
                sums[sum] = 0;
            }
            sums[sum]++;
            if (sums[sum] > maxcount)
            {
                maxcount = sums[sum];
                maxsum = sum;
            }
        }
    }

    std::list<int> maxs;
    for (pair<int,int> item : sums)
    {
        if (item.second == maxcount)
        {
            maxs.push_back(item.first);
        }
    }
    maxs.sort();
    for (int val : maxs)
    {
        cout << val << endl;
    }
}
