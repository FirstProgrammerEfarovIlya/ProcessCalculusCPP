#include "worker.h"
#include <cmath>

Worker::Worker(QObject *parent) : QObject(parent),
    __n(0), __result(0)
{
}


void Worker::set_param(unsigned long n)
{
    __n = n;
}


void Worker::process()
{
    __result = 0;
    unsigned long d = 1;
    qDebug() << "kek";
    if (__n != 0)
    {
        d = __n / 100;
    }
    else
    {
        emit this->progress(100);
    }

    qDebug() << "lol";
    for (unsigned long i =0; i <= __n; i++)
    {
        __result += sin(i);
        if (d != 0)
        {
            if (i % d == 0)
            {
                emit progress(static_cast<unsigned>(i / d));
            }
        }
    }
    emit finished();
}


double Worker::result() const
{
    return __result;
}


Worker::~Worker()
{
}
