#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int getDigit(int num, int id)
{
    int factor = (int) pow(10,id+1);
    double factor2 = (int) pow(10,id);
    int digit = (int) (num % factor)/factor2;
    //cout << num << " " << num % factor << " " << digit << endl;
    return digit; 
}

bool uniqueDigits(vector<int> digits)
{
    map<int,bool> values;
    for (int digit : digits)
    {
        values[digit] = true;
    }
    return values.size() == digits.size();
}

bool nonzero(vector<int> digits)
{
    for (int digit : digits)
    {
        if (digit == 0) return false;
    }
    return true;
}

bool divisible(unsigned int num, vector<int> digits)
{
    for (int digit : digits)
    {
        if (num % digit != 0) return false;
    }
    return true;
}

int main()
{
    int low, high;
    cin >> low;
    cin >> high;

    int count = 0;
    vector<int> digits = vector<int>(6);
    for (unsigned int i = low; i <= high; i++)
    {
        for (unsigned int k = 0; k < 6; k++)
        {
            digits[k] = getDigit(i,k);
        }

        if (uniqueDigits(digits) && nonzero(digits) && divisible(i, digits))
        {
            //cout << i << endl;
            count++;
        }
    }
    cout << count << endl;
}