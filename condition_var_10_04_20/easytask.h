#ifndef EASYTASK_H
#define EASYTASK_H

#include "task.h"


class EasyTask: public Task<int>
{
public:
    EasyTask();
    void run();
    ~EasyTask();
};

#endif // EASYTASK_H
