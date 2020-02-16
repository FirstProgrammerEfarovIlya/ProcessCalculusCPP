#include "sorter.h"


Sorter::Sorter(int *arr, int n, bool asc)
    :__asc(asc)
{
    setList(arr, n);
}


void Sorter::setList(int *arr, int n)
{
    __arr = arr;
    __n = n;
}


void Sorter::setDirect(bool asc)
{
    __asc = asc;
}


int Sorter::size() const
{
    return __n;
}


int* Sorter::list() const
{
    return __arr;
}


bool Sorter::direct() const
{
    return __asc;
}


void Sorter::bubleSort()
{
    for (int i = 0; i < __n; i++)
    {
        for (int j = 0; j < __n - i - 1; j++)
        {
            bool flag = __asc ? __arr[j] > __arr[j + 1]: __arr[j] < __arr[j + 1];
            if (flag)
            {
                std::swap(__arr[j], __arr[j + 1]);
            }
        }
    }
}


void Sorter::selectSort()
{
    for (int i = 0; i < __n - 1; i++)
    {
        int ind = i;
        for (int j = i + 1; j < __n; j++)
        {
            bool flag = __asc ? __arr[ind] > __arr[j]: __arr[ind] < __arr[j];
            if (flag)
            {
                ind = j;
            }
        }

        if (ind != i)
        {
            std::swap(__arr[ind], __arr[i]);
        }
    }
}


void Sorter::exchangeSort()
{
    for (int i = 0; i < __n - 1; i++)
    {
        for (int j = i + 1; j < __n; j++)
        {
            bool flag = __asc ? __arr[i] > __arr[j]: __arr[i] < __arr[j];
            if (flag)
            {
                std::swap(__arr[i], __arr[j]);
            }
        }
    }
}


Sorter::~Sorter()
{
}


void debugOutputList(const Sorter &sorter)
{
    QString ans = "[";
    for (int i = 0; i < sorter.__n; i++)
    {
        ans += QString::number(sorter.__arr[i]);
        if (i != sorter.__n - 1)
        {
            ans += ", ";
        }
    }
    ans += "]";
    qDebug() << ans;
}
