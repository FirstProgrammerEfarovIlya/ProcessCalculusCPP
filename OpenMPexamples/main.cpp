#include <iostream>
#include <ctime>
#include <cmath>
#include <omp.h>

using namespace std;


int example1()
{
    cout << "Serial command 1" << endl;

    #pragma omp parallel
    {
        cout << "Parallel command 2" << endl;
    }

    cout << "Serial command 3" << endl;
    return 0;
}


int example2()
{
    const int n = 10000;
    double a[n], b[n], c[n];

    clock_t t = clock();

    #pragma omp parallel for if(n >= 5000)          // использовать параллельные вычисления если размер массивов больше 5000
    for (int i = 0; i < n; i++)
    {
        a[i] = sin(i * 2.0);
        b[i] = sin(i / 3.0);
    }

    #pragma omp parallel for if(n >= 5000)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 10; j++)
        {
            c[i] += sin(a[i] * sin(c[i])) + sin(b[i] * sin(c[i]));
        }
    }
    cout << float(clock() - t) / CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}



int example3()
{
    cout << "serial start: 'Hello, world!!!';" << endl;

    #pragma omp parallel num_threads(3)                         // 3 потока исполняют параллельную область
    {
        printf("parallel %d: 'Hello, world!!!';\n", omp_get_thread_num());
    }

    cout << "serial end: 'Hello, world!!!';" << endl;
    return 0;
}


int example4()
{
    int n = 0;
    printf("serail start: n = %d\n", n);
    #pragma omp parallel private(n)
    {
        printf("parallel %d: n = %d\n", omp_get_thread_num(), n);
        n = 1;
        printf("parallel %d: n = %d\n", omp_get_thread_num(), n);
    }
    printf("serail end: n = %d\n", n);
    return 0;
}


int example5()
{
    int n = 0;
    printf("serial start: n = %d\n", n);

    #pragma omp parallel for lastprivate(n)             // сохранить значение n на последней итерации цикла
    for (int i = 0; i <= 100; i++)
    {
        n = i + i;
    }
    printf("serial end: n = %d\n", n);
    return 0;
}


int example6()
{
    int x = 1;
    // сделать локальные копии x,
    #pragma omp parallel reduction(*:x) num_threads(3) // после завершения области перемножить результаты потоков и поместить в глобальный x
    {
        x = 0;
        for (int i = 0; i < 10; i++)
        {
            x += 1;
        }
    }
    printf("x = %d;\n", x);
    return 0;
}


int example7()
{
    printf("start serial [0];\n");
    printf("===== start section 1 =====\n");
    omp_set_nested(true);
    #pragma omp parallel num_threads(2)
    {
        int n = omp_get_thread_num();
        printf("start parallel [%d];\n", n);
        #pragma omp parallel num_threads(4)
        {
            printf("    start parallel [%d, %d];\n", n, omp_get_thread_num());
            printf("    end parallel [%d, %d];\n", n, omp_get_thread_num());
        }
        printf("end parallel [%d];\n", n);
    }
    printf("===== end section 1 =====\n");

    printf("\n");

    printf("===== start section 2 =====\n");
    omp_set_nested(false);
    #pragma omp parallel num_threads(2)
    {
        int n = omp_get_thread_num();
        printf("start parallel [%d];\n", n);
        #pragma omp parallel num_threads(4)
        {
            printf("    start parallel [%d, %d];\n", n, omp_get_thread_num());
            printf("    end parallel [%d, %d];\n", n, omp_get_thread_num());
        }
        printf("end parallel [%d];\n", n);
    }
    printf("===== end section 2 =====\n");
    printf("end serial [0];\n");
    return 0;
}


int example8()
{
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            printf("thread %d;\n", omp_get_thread_num());
        }

        #pragma omp section
        {
            printf("thread %d;\n", omp_get_thread_num());
        }
    }
    return 0;
}


int example9()
{
    int num = 0;
    printf("serial 0: %d\n", num);
    #pragma omp parallel firstprivate(num) num_threads(3)
    {
        int id = omp_get_thread_num();
        num = 1;
        printf("parallel %d: %d\n", id, num);
        #pragma omp single copyprivate(num)                 // выполнит только один поток, изменив все локальные num на 101
        {
            num = 101;
            printf("parallel %d complete!!!\n", id);
        }
        printf("parallel %d: %d\n", id, num);
    }
    printf("serial 0: %d\n", num);
    return 0;
}


int example10()
{
    printf("start serial 0\n");
    #pragma omp parallel num_threads(3)
    {
        int id = omp_get_thread_num();
        printf("start parallel %d\n", id);
        #pragma omp single
        {
            printf("parallel %d complete single 1!!!\n", id);
        }

        #pragma omp single nowait
        {
            printf("parallel %d complete single 2!!!\n", id);
        }
        printf("end parallel %d\n", id);
    }
    printf("end serial 0\n");
    return 0;
}



int example11()
{
    int num = 0;
    printf("serial 0: %d\n", num);
    #pragma omp parallel firstprivate(num)
    {
        num += 1;
        #pragma omp master
        {
            num += 1;
        }
        printf("parallel %d: %d\n", omp_get_thread_num(), num);
    }
    printf("serial 0: %d\n", num);
    return 0;
}



int main()
{
    return example11();
}
