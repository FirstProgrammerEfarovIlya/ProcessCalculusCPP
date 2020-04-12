#ifndef TASK_H
#define TASK_H


#include <vector>
#include <chrono>
#include <thread>

/* Abstract class who descript interface for base task */

enum TaskError {InvalidParamsError};


template <class T>
class Task
{
protected:
    std::vector<T> __params;
    T __result;

public:
    Task();

    void setParams(const std::vector<T> &params);
    void setParams(std::vector<T> &&params);
    virtual void run() = 0;
    T result() const;

    virtual ~Task();
};

#include "task.cpp"

#endif // TASK_H
