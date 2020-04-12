#include "main_work.h"

static std::mutex mutex_var;
static std::condition_variable cond_var;
static std::queue<Task<int>*> tasks;
volatile static bool done = false;
static int count_tasks = 5;

void func_produce()
{
    std::this_thread::yield();

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::unique_lock<std::mutex> lock(mutex_var);

        for (int i = 0; i < count_tasks; i++)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            int r = rand() % 3;
            Task<int> *task;
            std::cout << "Producer generate task: {";
            switch(r)
            {
                case 0:
                    task = new EasyTask;
                    std::cout << " EasyTask ";
                break;

                case 1:
                    task = new MediumTask;
                    std::cout << " MediumTask ";
                break;

                default:
                    task = new DifficultTask;
                    std::cout << " DifficultTask ";
            }
            int param = rand() % 10 + 1;
            std::cout << " param = " << param << "}" << std::endl;
            task->setParams({param});
            tasks.push(task);
        }

        std::cout << "===========================================" << std::endl;
        std::cout << "Producer generating N tasks!!! Notify consumer!!!" << std::endl;
        std::cout << "===========================================" << std::endl;
        done = true;
        cond_var.notify_one();
    }
}


void func_comsume()
{
    while(true)
    {
        std::unique_lock<std::mutex> lock(mutex_var);
        cond_var.wait(lock, [&]{return done;});         // protection from false positives

        if (int(tasks.size()) >= count_tasks)
        {
            while (!tasks.empty())
            {
                Task<int>* task = tasks.front();
                tasks.pop();
                task->run();
                std::cout << "Consumer peform task: {"
                          << "result = " << task->result() << "}" << std::endl;
                delete task;
            }
            std::cout << "===========================================" << std::endl;
            std::cout << "Consumer end peforming!!!" << std::endl;
            std::cout << "===========================================" << std::endl;
        }
        done = false;
    }
}






