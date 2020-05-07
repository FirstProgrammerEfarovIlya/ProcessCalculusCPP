#include <omp.h>
#include <iostream>
#include <cstdio>
#include <iomanip>


struct node
{
    node* next;
    int value;
};


int factorial(int n)
{
    int p = 1;
    for (int i = 2; i <= n; i++)
    {
        p *= i;
    }
    return p;
}


node* create_list(int size = 0)
{
    node *head, *last, *curr;
    head = last = curr = nullptr;
    
    for (int i = 0; i < size; i++)
    {
        curr = new node();
        if (head)
        {
            last->next = curr;
        }
        else
        {
            head = curr;
        }
        last = curr;
    }
    return head;
}


void delete_list(node*& head)
{
    node* curr;
    while (head)
    {
        curr = head;
        head = head->next;
        delete curr;
    }
}


void print_list(const node* head)
{
    int count = 0;

    std::cout << "{ ";
    const node* curr = head;
    while (curr)
    {
        std::cout << curr->value << "; ";
        curr = curr->next;
        count++;
        if (count % 11 == 0)
        {
            std::cout << std::endl;
        }
    }
    std::cout << "}" << std::endl;
}


int main()
{
    const int n = 100000;
    node* head = create_list(n);

    std::cout << std::fixed;

    //print_list(head);

    double t0;

    t0 = omp_get_wtime();

    node* curr = head;
    int count = 0;
    while (curr)
    {
        curr->value = factorial(count);
        curr = curr->next;
        count++;
    }

    std::cout << "time serial: " << omp_get_wtime() - t0 << std::endl;

    //print_list(head);

    delete_list(head);

    head = create_list(n);

    //print_list(head);

    t0 = omp_get_wtime();

    #pragma omp parallel shared(head)
    {
        #pragma omp single nowait
        {
            node* curr = head;
            int count = 0;
            while (curr)
            {
                #pragma omp task firstprivate(curr, count)
                {
                    //std::printf("parallel th #%d is work!!!;\n", omp_get_thread_num());
                    curr->value = factorial(count);
                }
                curr = curr->next;
                count++;
            }
        }
    }

    std::cout << "time parallel: " << omp_get_wtime() - t0 << std::endl;

    //print_list(head);

    delete_list(head);
    return 0;
}
