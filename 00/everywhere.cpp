#include <iostream>
#include <set>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int numCities;
        cin >> numCities;
        std::set<std::string> cities;
        for (int j = 0; j < numCities; j++)
        {
            std::string city;
            cin >> city;
            cities.insert(city);
        }
        cout << cities.size() << endl;
    }
    return 0;
}
