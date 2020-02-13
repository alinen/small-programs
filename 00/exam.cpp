#include <iostream>

using namespace std;
int main()
{
    int numCorrect;
    string myExam;
    string friendExam;
    cin >> numCorrect;
    cin >> myExam;
    cin >> friendExam;

    int numSame = 0;
    for (int i = 0; i < myExam.size(); i++)
    {
        if (myExam[i] == friendExam[i]) numSame++;
    }

    int n = myExam.size();
    int numDifferent = n - numSame;
    int numWrong = n - numCorrect;
    int bestScore = min(numWrong, numDifferent) + min(numCorrect, numSame);
    cout << bestScore << endl;
}
