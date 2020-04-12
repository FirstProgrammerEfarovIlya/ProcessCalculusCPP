#include "main_work.h"
#include <ctime>

using namespace std;

int main()
{
    srand(unsigned(time(nullptr)));
    thread producer(func_produce);
    thread consumer(func_comsume);

    producer.join();
    consumer.join();
    return 0;
}
