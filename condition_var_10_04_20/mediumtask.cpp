#include "mediumtask.h"

MediumTask::MediumTask()
{
    __result = 0;
}


void MediumTask::run()
{
    if (__params.size() < 1)
    {
        throw InvalidParamsError;
    }

    // calculate number fibonachi
    // Fn = Fn-1 + Fn-2

    __result = 0;
    int f1 = 0;
    int f2 = 1;

    for (int i = 1; i <= __params[0]; i++)
    {
        __result = f1 + f2;
        f2 = f1;
        f1 = __result;
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
}


MediumTask::~MediumTask()
{
}
