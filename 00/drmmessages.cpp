#include <iostream>

using namespace std;
int main()
{
    string code;
    cin >> code;
    int size = code.size()/2;

    int sum1 = 0;
    for (int i = 0; i < size; i++)
    {
        code[i] = code[i] - 'A';
        sum1 += code[i];
    }
    int sum2 = 0;
    for (int i = 0; i < size; i++)
    {
        code[i+size] = code[i+size] - 'A';
        sum2 += code[i+size];
    }

    for (int i = 0; i < size; i++)
    {
        code[i] = (code[i] + sum1) % 26;
    }
    for (int i = 0; i < size; i++)
    {
        code[i+size] = (code[i+size] + sum2) % 26;
    }

    for (int i = 0; i < size; i++)
    {
        code[i] = (code[i] + code[i+size]) % 26 + 'A';
        cout << code[i];
    }
}