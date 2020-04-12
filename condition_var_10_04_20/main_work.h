#ifndef MAIN_WORK_H
#define MAIN_WORK_H

#include <mutex>
#include <queue>
#include <condition_variable>
#include "easytask.h"
#include "difficulttask.h"
#include "mediumtask.h"
#include <iostream>
#include <thread>
#include <chrono>


void func_produce();

void func_comsume();

#endif // MAIN_WORK_H
