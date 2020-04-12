#include "easytask.h"

EasyTask::EasyTask()
{
    __result = 0;
}


void EasyTask::run()
{
    if (__params.size() < 1)
    {
        throw InvalidParamsError;
    }

    // calculate factorial
    __result = 1;
    for (int i = 1; i <= __params[0]; i++)
    {
        __result *= i;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}


EasyTask::~EasyTask()
{
}
