#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point
{
    int x;
    int y;
};

int ManhattenDistance(const vector<Point>& points, int i, int j)
{
    if (i == j) return 0;
    int dx = abs(points[i].x - points[j].x);
    int dy = abs(points[i].y - points[j].y);
    return  dx + dy;
} 

int main()
{
    int N = 0;
    cin >> N;

    if (N == 2)
    {
        cout << "0" << endl;
        return 0;
    }

    int dmax = 0;
    int maxi = -1;
    int maxj = -1;
    vector<Point> points = vector<Point>(N);
    for (int i = 0; i < N; i++)
    {
        int x = 0, y = 0;
        cin >> x;
        cin >> y;
        points[i] = Point{x,y};
        for (int j = 0; j < i-1; j++)
        {
            int d = ManhattenDistance(points, i, j);
            if (d > dmax)
            {
                dmax = d;
                maxi = i;
                maxj = j;
            }
        }
    }

    vector<int> group1;
    group1.push_back(maxi);

    vector<int> group2;
    group2.push_back(maxj);

    //cout << "dmax " << dmax << " i " << maxi << " j " << maxj << endl;
    int max1 = 0; // max group 1
    int max2 = 0; // max group 2
    for (int i = 0; i < N; i++)
    {
        if (i == maxi) continue;
        if (i == maxj) continue;

        int d1 = ManhattenDistance(points, i, maxi);
        int d2 = ManhattenDistance(points, i, maxj);
        //cerr << i << " " << d1 << " " << d2 << endl;
        if (d1 < d2)
        {
            for (int j = 0; j < group1.size(); j++)
            {
                int idx = group1[j];
                max1 = max(ManhattenDistance(points, idx, i), max1); 
            }
            group1.push_back(i);
        }
        else if (d2 > d1)
        {
            for (int j = 0; j < group2.size(); j++)
            {
                int idx = group2[j];
                max2 = max(ManhattenDistance(points, idx, i), max2); 
            }
            group2.push_back(i);
        }
        else
        {
            int tmp1 = max1;
            for (int j = 0; j < group1.size(); j++)
            {
                int idx = group1[j];
                tmp1 = max(ManhattenDistance(points, idx, i), tmp1); 
            }

            int tmp2 = max2;
            for (int j = 0; j < group2.size(); j++)
            {
                int idx = group2[j];
                max2 = max(ManhattenDistance(points, idx, i), tmp2); 
            }

            if (tmp1 < tmp2)
            {
                max1 = max(tmp1, max1);
                group1.push_back(i);
            } 
            else 
            {
                max2 = max(tmp2, max2);
                group2.push_back(i);
            }
        }
        // TODO: If equal, choose the group with the smallest max distance
    }

    cout << max(max1, max2) << endl;

    return 0;
}
