#include "task.h"

template <class T>
Task<T>::Task()
{
}


template <class T>
void Task<T>::setParams(const std::vector<T> &params)
{
    __params = params;
}


template <class T>
void Task<T>::setParams(std::vector<T> &&params)
{
    __params = params;
}


template <class T>
T Task<T>::result() const
{
    return __result;
}


template <class T>
Task<T>::~Task()
{
}

