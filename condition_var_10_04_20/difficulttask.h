#ifndef DIFFICULTTASK_H
#define DIFFICULTTASK_H


#include "task.h"


class DifficultTask: public Task<int>
{
public:
    DifficultTask();
    void run();
    ~DifficultTask();
};

#endif // DIFFICULTTASK_H
