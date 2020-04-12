#include "difficulttask.h"

DifficultTask::DifficultTask()
{
}


void DifficultTask::run()
{
    if (__params.size() < 1)
    {
        throw InvalidParamsError;
    }

    if (__params[0] < 1)
    {
        throw InvalidParamsError;
    }

    // calculate near prime number less than or equal to a given
    bool *flags = new bool[__params[0]];

    for (int i = 1; i < __params[0]; i++)
    {
        for (int j = i + 1; j < __params[0]; j++)
        {
            if (!flags[j])
            {
                if ((j + 1) % (i + 1) == 0)
                {
                    flags[j] = true;
                }
            }
        }
    }

    for (int i = __params[0] - 1; i >= 0; i--)
    {
        if (!flags[i])
        {
            __result = i + 1;
            break;
        }
    }

    delete [] flags;

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

DifficultTask::~DifficultTask()
{
}
