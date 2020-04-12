#include <iostream>
#include <thread>
#include <ctime>
#include <cmath>
#include <sys/time.h>
#include <iomanip>

using namespace std;

const int MAX_COUNT_SIN = 20;


void calc_sum(int *arr, int n, int index, int step, int &sum)
{
    sum = 0;
    for (int i = index; i < n; i += step)
    {
        int element = arr[i];
        for (int j = 0; j < MAX_COUNT_SIN; j++)
        {
            element = int(10 * sin(element));
        }
        sum += element;
    }
}


void rand_array(int *arr, int n, int a = 0, int b = 10)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (b - a) + a;
    }
}


void print_array(int *arr, int n)
{
    cout << "{ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ";";
    }
    cout << "}" << endl;
}


int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    cout << "Programm: many thread calculate sum" << endl;
    cout << endl;

    int n, m;
    do
    {
        cout << "n elements = ";
        cin >> n;
    }
    while(n <= 0);

    do
    {
        cout << "m threads = ";
        cin >> m;
    }
    while (m > n || m <= 0);

    struct timeval tv0, tv1;        // time variables
    gettimeofday(&tv0, nullptr);

    int *arr = new int[n];
    int *sums = new int[m];

    rand_array(arr, n);
    //print_array(arr, n);

    std::thread **ths = new std::thread*[m];

    for (int i = 0; i < m; i++)
    {
        ths[i] = new std::thread(calc_sum, arr, n, i, m, std::ref(sums[i]));
    }


    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        ths[i]->join();
    }

    for (int i = 0; i < m; i++)
    {
        sum += sums[i];
    }

    //print_array(sums, m);

    cout << "sum: " << sum << endl;

    delete [] arr;
    delete [] sums;
    for (int i = 0; i < m; i++)
    {
        delete ths[i];
    }
    delete [] ths;

    gettimeofday(&tv1, nullptr);

    cout << "time: " << static_cast<double>(tv1.tv_usec - tv0.tv_usec) / 1000000
                        + static_cast<double>(tv1.tv_sec - tv0.tv_sec) << " sec" << endl;
    return 0;
}



//int main()
//{
//    srand(static_cast<unsigned>(time(nullptr)));
//    const int max_count = 200000000;
//    for (int m = 1; m <= 10; m++)
//    {
//        for (int n = 140000000; n <= max_count; n += 10000000)
//        {
//            struct timeval tv0, tv1;        // time variables
//            gettimeofday(&tv0, nullptr);

//            int *arr = new int[n];
//            int *sums = new int[m];
//            rand_array(arr, n);

//            std::thread **ths = new std::thread*[m];

//            for (int i = 0; i < m; i++)
//            {
//                ths[i] = new std::thread(calc_sum, arr, n, i, m, std::ref(sums[i]));
//            }


//            int sum = 0;
//            for (int i = 0; i < m; i++)
//            {
//                ths[i]->join();
//            }

//            for (int i = 0; i < m; i++)
//            {
//                sum += sums[i];
//            }

//            delete [] arr;
//            delete [] sums;
//            for (int i = 0; i < m; i++)
//            {
//                delete ths[i];
//            }
//            delete [] ths;

//            gettimeofday(&tv1, nullptr);

//            double time = static_cast<double>(tv1.tv_usec - tv0.tv_usec) / 1000000
//                    + static_cast<double>(tv1.tv_sec - tv0.tv_sec);

////            cout << "n: " << n << "; m: " << m << "; time: " << fixed << setprecision(9) << time << endl;
//            cout << n << ";" << m << ";" << fixed << setprecision(9) << time << endl;
//        }
//    }
//    return 0;
//}
