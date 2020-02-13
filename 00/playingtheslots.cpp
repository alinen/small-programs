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
    //if (L < 0 || L > baL) return 101;

    float x = pax - L * bax / baL;
    float y = pay - L * bay / baL;
    float d = sqrt(x*x + y*y);
    //cout << "x,y " << x << " " << y << " " << d << endl;
    return d;
}

bool isColinear(int i, const std::vector<Point>& poly)
{
    int N = poly.size();
    Point p1 = poly[i-1 < 0? N-1 : i-1];
    Point p2 = poly[(i) % N];
    Point p3 = poly[(i+1) % N];
    Point v1{p2.x-p1.x, p2.y-p1.y};
    Point v2{p3.x-p2.x, p3.y-p2.y};
    float cross = v1.x * v2.y - v1.y * v2.x;
    return fabs(cross) < 0.000001; 
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


    float pmin = 100001;
    for (int i = 0; i < N; i++)
    {
        int a = (i+0) % N;
        int b = (i+1) % N;
        float pmax = 0; // find farthest point
        for (int j = 2; j < N; j++)
        {
            int idx = (i+j) % N;
            //if (isColinear(idx, poly)) continue;
            float d = Project(poly, idx, a, b);
            //cout << " idx " << idx << " side " << a << "," << b << " d " << d << endl;
            pmax = max(d, pmax);
        }
        if (pmax > 0.000001) pmin = min(pmax, pmin);
    }

    cout << pmin << endl;
    return 0;

}
