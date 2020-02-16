#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->th = new QThread(this);

    this->worker = new Worker();

    connect(th, &QThread::started, worker, &Worker::process);
    connect(worker, &Worker::finished, th, &QThread::quit);
    connect(worker, &Worker::finished, this, &MainWindow::update_result);

    connect(worker, &Worker::progress, ui->progressBar, &QProgressBar::setValue);
    connect(worker, SIGNAL(progress(uint)), this, SLOT(update()));
}

MainWindow::~MainWindow()
{
    delete th;
    delete worker;
    delete ui;
}


void MainWindow::update_result()
{
    ui->lb_result->setText("Result: " + QString::number(worker->result()));
}


void MainWindow::on_bt_here_clicked()
{
    unsigned long n = static_cast<unsigned long>(ui->spinBox->value());
    worker->moveToThread(QApplication::instance()->thread());
    worker->set_param(n);

    ui->lb_result->setText("calculation...");
    worker->process();
    update_result();
}

void MainWindow::on_bt_thread_clicked()
{
    worker->set_param(static_cast<unsigned long>(ui->spinBox->value()));
    worker->moveToThread(th);
    ui->lb_result->setText("calculation...");
    th->start();
}
