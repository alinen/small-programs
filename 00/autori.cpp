#include <iostream>
using namespace std;

int main()
{
    std::string authors;
    cin >> authors;
    std::string abbrev;
    abbrev += authors[0];
    for (int i = 1; i < authors.size(); i++)
    {
        if (authors[i] == '-')
        {
            abbrev += authors[i+1];
        }
    }
    cout << abbrev;
    return 0;
}
