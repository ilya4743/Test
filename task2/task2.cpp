#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    double diff = fabs(a - b);
    if (diff <= absEpsilon)
        return true;

    return diff <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}

int main(int argc, char* argv[])
{
    float x1, y1, r;
    float x2, y2;
    float d;

    ifstream in1(argv[1]);
    if (in1.is_open())
    {
        in1 >> x1 >> y1 >> r;
    }
    in1.close();

    ifstream in2(argv[2]);
    if (in2.is_open())
    {
        while (!in2.eof())
        {
            in2 >> x2 >> y2;
            d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
            if (approximatelyEqualAbsRel(d, r, 1e-12, 1e-8))cout << "0\n";
            if (d < r)cout << "1\n";
            if (d > r)cout << "2\n";
        }
    }
    in2.close();

    return 0;
}