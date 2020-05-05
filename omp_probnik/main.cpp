#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    const int len = 100000;
    int a[len], b[len];
    double c[len];
    clock_t t0 = clock();

    for (int i = 0; i < len; i++)
    {
        a[i] = i;
        b[i] = i;
    }

    #pragma omp parallel for
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            c[i] += a[i] * b[i] * a[i] * b[i];
            c[i] += sin(a[i] * sin(c[i])) * sin(b[i] * sin(c[i])) * sin(a[i] * sin(c[i])) * sin(b[i] * sin(c[i]));
            c[i] += sin(c[i] * sin(c[i]));
        }
    }

    cout << "time: " << (float(clock() - t0)/CLOCKS_PER_SEC) << " sec" << endl;
    return 0;
}
