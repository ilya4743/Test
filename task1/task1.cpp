#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char* argv[])
{
    int n, m;

    n = atoi(argv[1]);
    m = atoi(argv[2]);

    int* a = new int[n];

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    int k = 0;
    int u = 1;
    do
    {
        cout << a[k];
 
        if (m > n) 
            k += (m % n)-1;
        else
            k += (m - 1);
        if (k >= n) k -= n;
    } while (a[0] != a[k]);

    delete[]a;
    return 0;
}