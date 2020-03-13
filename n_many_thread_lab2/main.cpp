#include <iostream>
#include <thread>
#include <ctime>
#include <sys/time.h>
#include <iomanip>

using namespace std;


//void calc_sum(int *arr, int n, int index, int step, int &sum)
//{
//    sum = 0;
//    for (int i = index; i < n; i += step)
//    {
//        sum += arr[i];
//    }
//}


//void rand_array(int *arr, int n, int a = 0, int b = 10)
//{
//    for (int i = 0; i < n; i++)
//    {
//        arr[i] = rand() % (b - a) + a;
//    }
//}


//void print_array(int *arr, int n)
//{
//    cout << "{ ";
//    for (int i = 0; i < n; i++)
//    {
//        cout << arr[i] << ";";
//    }
//    cout << "}" << endl;
//}


//int main()
//{
//    srand(static_cast<unsigned>(time(nullptr)));
//    int n, m;
//    do
//    {
//        cout << "n elements = ";
//        cin >> n;
//    }
//    while(n <= 0);

//    do
//    {
//        cout << "m threads = ";
//        cin >> m;
//    }
//    while (m > n || m <= 0);

//    struct timeval tv0, tv1;        // time variables
//    gettimeofday(&tv0, nullptr);

//    int *arr = new int[n];
//    int *sums = new int[m];

//    rand_array(arr, n);
//    //print_array(arr, n);

//    std::thread **ths = new std::thread*[m];

//    for (int i = 0; i < m; i++)
//    {
//        ths[i] = new std::thread(calc_sum, arr, n, i, m, std::ref(sums[i]));
//    }


//    int sum = 0;
//    for (int i = 0; i < m; i++)
//    {
//        ths[i]->join();
//    }

//    for (int i = 0; i < m; i++)
//    {
//        sum += sums[i];
//    }

//    //print_array(sums, m);

//    cout << "sum: " << sum << endl;

//    delete [] arr;
//    delete [] sums;
//    for (int i = 0; i < m; i++)
//    {
//        delete ths[i];
//    }
//    delete [] ths;

//    gettimeofday(&tv1, nullptr);

//    cout << "time: " << static_cast<double>(tv1.tv_usec - tv0.tv_usec) / 1000000
//                        + static_cast<double>(tv1.tv_sec - tv0.tv_sec) << " sec" << endl;
//    return 0;
//}


void calc_sum(int *arr, long int n, long int index, int step, long int &sum)
{
    sum = 0;
    for (long int i = index; i < n; i += step)
    {
        sum += arr[i];
    }
}


void rand_array(int *arr, long int n, int a = 0, int b = 10)
{
    for (long int i = 0; i < n; i++)
    {
        arr[i] = rand() % (b - a) + a;
    }
}


int main()
{
    srand(static_cast<unsigned>(time(nullptr)));
    const long int max_count = 100000000;
    for (int m = 1; m <= 10; m++)
    {
        for (long int n = 10; n <= max_count; n *= 10)
        {
            struct timeval tv0, tv1;        // time variables
            gettimeofday(&tv0, nullptr);

            int *arr = new int[n];
            long int *sums = new long int[m];
            rand_array(arr, n);

            std::thread **ths = new std::thread*[m];

            for (int i = 0; i < m; i++)
            {
                ths[i] = new std::thread(calc_sum, arr, n, i, m, std::ref(sums[i]));
            }


            long int sum = 0;
            for (int i = 0; i < m; i++)
            {
                ths[i]->join();
            }

            for (int i = 0; i < m; i++)
            {
                sum += sums[i];
            }

            delete [] arr;
            delete [] sums;
            for (int i = 0; i < m; i++)
            {
                delete ths[i];
            }
            delete [] ths;

            gettimeofday(&tv1, nullptr);

            double time = static_cast<double>(tv1.tv_usec - tv0.tv_usec) / 1000000
                    + static_cast<double>(tv1.tv_sec - tv0.tv_sec);

            cout << "n: " << n << "; m: " << m << "; time: " << fixed << setprecision(9) << time << endl;
        }
    }
    return 0;
}