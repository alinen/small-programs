#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

float distance(float x1, float y1, float x2, float y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    float x,y,x1,y1,x2,y2; // possible bug: wrong types
    cin >> x;
    cin >> y;
    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2; // possible bugs: swapping arguments; reading things in wrong order

    // check closest distance of (x,y) with axis aligned box
    float minDistance = numeric_limits<float>::max();
    if (x >= x1 && x <= x2)
    {
        minDistance = min(fabs(y-y2), fabs(y-y1));
    }
    else if (y >= y1 && y <= y2)
    {
        minDistance = min(fabs(x-x2), fabs(x-x1));
    }
    else // check corners
    {
        minDistance = min(minDistance, distance(x,y,x1,y1));
        minDistance = min(minDistance, distance(x,y,x1,y2));
        minDistance = min(minDistance, distance(x,y,x2,y2));
        minDistance = min(minDistance, distance(x,y,x2,y1));
    }
    std::cout << minDistance << std::endl;
}
