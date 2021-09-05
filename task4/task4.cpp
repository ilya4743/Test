#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    vector<int> nums;
    int r1 = 0, r2 = 0;

    ifstream in(argv[1]);
    if (in.is_open())
    {
        while (!in.eof())
        {
            int b;
            in >> b;
            nums.push_back(b);
        }
    }
    in.close();

    sort(nums.begin(), nums.end());

    if (nums.size() % 2 == 0)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            r1 += abs(nums[nums.size() / 2] - nums[i]);
            r2 += abs(nums[(nums.size()) / 2 - 1] - nums[i]);
        }
        if (r1 >= r2) cout << r2 << endl;
        else
            cout << r1 << endl;
    }
    else
    {
        for (int i = 0; i < nums.size(); i++)
        {
            r1 += abs(nums[nums.size() / 2] - nums[i]);
        }
        cout << r1 << endl;
    }

    return 0;
}