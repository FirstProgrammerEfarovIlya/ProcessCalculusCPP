#ifndef MEDIUMTASK_H
#define MEDIUMTASK_H

#include "task.h"


class MediumTask: public Task<int>
{
public:
    MediumTask();
    void run();
    ~MediumTask();
};

#endif // MEDIUMTASK_H
