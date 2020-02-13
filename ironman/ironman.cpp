#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void computeGradient(const vector<float>& x, 
                     const vector<float>& y,
                     const vector<float>& speeds, 
                     float totalx, // needed for soft constraint
                     vector<float>& gradient)
{
    float sum = -totalx;
    for (int i = 0; i < x.size(); i++)
    {
        sum += x[i];
    }
    for (int i = 0; i < y.size(); i++)
    {
        float denom = speeds[i] * sqrt(x[i]*x[i] + y[i]*y[i]);
        gradient[i] = x[i] / denom + 2 * sum;
    }
}

float computeTime(const vector<float>& x, 
                     const vector<float>& y,
                     const vector<float>& speeds) 
{
    float total = 0;
    for (int i = 0; i < x.size(); i++)
    {
        float distance = sqrt(x[i]* x[i] + y[i] * y[i]);
        total += distance / speeds[i];
    }
    return total;
}

float computeObjective(const vector<float>& x, 
                     const vector<float>& y,
                     const vector<float>& speeds, 
                     float totalx, float totaly,
                     float gamma,
                     const vector<float>& gradient)
{
    vector<float> newx;
    float len = 0;
    for (int i = 0; i < x.size(); i++)
    {
        float val = x[i] - gamma * gradient[i];
        newx.push_back(val);
        len += val;
    }
    float total = 0;
    for (int i = 0; i < x.size(); i++)
    {
        //newx[i] = totalLength * newx[i]/len;
        float distance = sqrt(newx[i]* newx[i] + y[i] * y[i]);
        total += distance / speeds[i];
    }
    return total;
}

void updateX(vector<float>& x, 
             float totalx, float totaly, float gamma,
             const vector<float>& gradient)
{
    float len = 0;
    for (int i = 0; i < x.size(); i++)
    {
        float val = x[i] - gamma * gradient[i];
        x[i] = val; 
        len += val;
    }
    //float total = 0;
    //for (int i = 0; i < x.size(); i++)
    //{
    //    x[i] = totalx * x[i]/len;
    //}
}

int main()
{
    float xs, ys;
    float xf, yf;
    int numLayers;
    vector<float> ystarts;
    vector<float> speeds;

    cin >> xs; 
    cin >> ys;
    cin >> xf; 
    cin >> yf;
    cin >> numLayers;
    cout << numLayers << endl;
    cout << "xs " << xs << endl;
    cout << "xf " << xf << endl;
    cout << "ys " << ys << endl;
    cout << "yf " << yf << endl;

    vector<float> yheights;
    for (int i = 0; i < numLayers-1; i++)
    {
        float val;
        cin >> val;
        ystarts.push_back(val);
        yheights.push_back(i == 0? val - ys : val - ystarts[i-1]);
    }
    ystarts.push_back(yf);
    yheights.push_back(yf - ystarts[numLayers-2]);

    // sanity check
    for (int i = 0; i < yheights.size(); i++)
    {
        cout << yheights[i] << endl;
    }

    float totalSpeed = 0; // for weighted sum
    for (int i = 0; i < numLayers; i++)
    {
        float val;
        cin >> val;
        speeds.push_back(val);
        totalSpeed += val;
    }

    float totalx = xf - xs;
    float totaly = yf - ys;
    vector<float> xwidths; // unknowns, buffer 1
    vector<float> gradient; // for searching
    for (int i = 0; i < numLayers; i++)
    {
        float startEstimate = speeds[i] * (totalx/totalSpeed);
        xwidths.push_back(startEstimate);
        cout << "startx " << startEstimate << endl;
        gradient.push_back(0);
    }

    float total = computeTime(xwidths, yheights, speeds);
    cout << "start total " << total << endl;

    float gamma = 1;
    for (int t = 0; t < 10; t++) // todo check for convergence
    {
        computeGradient(xwidths, yheights, speeds, totalx, gradient);
        float total = computeObjective(xwidths, yheights, speeds, totalx, totaly, gamma, gradient);
        updateX(xwidths, totalx, totaly, gamma, gradient);
        cout << "iter total " << total << endl;
    }

    total = computeTime(xwidths, yheights, speeds);
    cout << total << endl;
}

/*

   float lambda = 0.0;
    float lambdaDot;
    float gamma = 0.0001;
    for (int t = 0; t < 500; t++) // todo check for convergence
    {
        computeGradient(xwidths, yheights, speeds, gradient);
        lambdaDot = -totalLength;
        for (int i = 0; i < xwidths.size(); i++) lambdaDot += xwidths[i];
        lambda = lambda + gamma * lambdaDot; 
        cout << "lambda " << lambda << " " << lambdaDot << endl;

        for (int i = 0; i < xwidths.size(); i++)
        {
            xwidths[i] = xwidths[i] - gamma * (gradient[i] + lambda);
            cout << "x " << i <<  " " << xwidths[i] << endl;
        }

        float newtotal = computeTime(xwidths, yheights, speeds);
        cout << "iter total " << newtotal << endl;
        total = newtotal;
    }

    total = computeTime(xwidths, yheights, speeds);
    cout << total << endl;

*/

/*
    // To minimize time, we should maximize 
    // paths in her fastest zones and minimize 
    // paths in slowest zones
    float x = xs;
    float y = ys;
    float total = 0;
    for (int i = 0; i < ystarts.size(); i++)
    {
        float dx, dy;
        if (i == fastestZone) // our chance to move over
        {
            dx = xf - x;
            dy = yf - y;
            float len = sqrt(dx * dx + dy * dy);
            dx = dx / len;
            dy = dy / len;
        }
        else
        {
            dx = 0;
            dy = ys < yf? 1 : -1;
        }
        cout << "dx,dy " << dx << " " << dy << endl;

        float d = (ystarts[i] - y)/dy;
        y = y + d * dy;
        x = x + d * dx;
        cout << "d " << d << " x,y " << x << " " << y <<endl;
        total += d / speeds[i];
    }
    */