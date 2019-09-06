#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
struct Point
{
    float x;
    float y;
};

float Project(const vector<Point>& poly, int i, int sidei, int sidej)
{
    float pax = poly[i].x - poly[sidei].x;
    float pay = poly[i].y - poly[sidei].y;
    //cout << "pax, pay " << pax << " " << pay << endl;

    float bax = poly[sidej].x - poly[sidei].x;
    float bay = poly[sidej].y - poly[sidei].y;
    float baL = sqrt(bax*bax + bay*bay);
    //cout << "bax, bay " << bax << " " << bay << " " << baL << endl;

    float L = pax * bax / baL + pay * bay / baL;
    //cout << "L" << " " << L << endl;
    if (L < 0 || L > baL) return 101;

    float x = pax - L * bax / baL;
    float y = pay - L * bay / baL;
    float d = sqrt(x*x + y*y);
    //cout << "x,y " << x << " " << y << " " << d << endl;
    return d;
}

int main()
{
    int N;
    cin >> N;

    vector<Point> poly = vector<Point>(N);
    for (int i = 0; i < N; i++)
    {
        float x, y;
        cin >> x;
        cin >> y;
        poly[i] = Point{x,y};
    } 

    float pmin = 101;
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < N-1; j++)
        {
            int a = (i+j) % N;
            int b = (i+j+1) % N;
            float d = Project(poly, i, a, b);
            //cout << " i " << i << " side " << a << " , " << b << " d " << d << endl;
            pmin = min(d, pmin);
        }
    }

    cout << pmin << endl;
    return 0;

}
