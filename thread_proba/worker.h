#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>

class Worker : public QObject
{
    Q_OBJECT

    unsigned long __n;
    double __result;

public:
    explicit Worker(QObject *parent = nullptr);

    void set_param(unsigned long n);

    double result() const;

    ~Worker();

signals:
    void finished();

    void progress(unsigned i);

public slots:
    void process();
};

#endif // WORKER_H
