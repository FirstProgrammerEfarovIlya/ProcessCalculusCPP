// example_parallel_for1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <omp.h>
#include <ctime>
#include <cstdlib>


template <class T, class size>
void print_array(T* arr, size n)
{
	std::cout << "{ ";
	for (size i = 0; i < n; i++)
	{
		std::cout << arr[i] << "; ";
		if ((i + 1) % 11 == 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << "}" << std::endl;
}


bool example1(const long int& n)
{
	srand(time(nullptr));

	double* a = new double[n];
	double* b = new double[n];
	double* c = new double[n];

	for (long i = 0; i < n; i++)
	{
		a[i] = float(rand()) / RAND_MAX;
		b[i] = float(rand()) / RAND_MAX;
	}

	//print_array(a, n);
	//print_array(b, n);

	double t0 = omp_get_wtime();

	for (long i = 0; i < n; i++)
	{
		c[i] = a[i] + b[i];
	}
	
	std::cout << "time1: " << (omp_get_wtime() - t0) << std::endl;

	//print_array(c, n);

	delete[] a;
	delete[] b;
	delete[] c;

	return true;
}


bool example2(const long int& n)
{
	srand(static_cast<unsigned>(time(nullptr)));

	double* a = new double[n];
	double* b = new double[n];
	double* c = new double[n];

	for (long i = 0; i < n; i++)
	{
		a[i] = float(rand()) / RAND_MAX;
		b[i] = float(rand()) / RAND_MAX;
	}

	//print_array(a, n);
	//print_array(b, n);

	double t0 = omp_get_wtime();

	#pragma omp parallel shared(a, b, c)
	{
		#pragma omp for schedule(guided)
		for (long i = 0; i < n; i++)
		{
			c[i] = a[i] + b[i];
		}
	}

	std::cout << "time2: " << (omp_get_wtime() - t0) << std::endl;

	//print_array(c, n);

	delete[] a;
	delete[] b;
	delete[] c;

	return true;
}


int example0()
{
	const long int n = 40000000;
	return example1(n) &&
		example2(n);
}


int main()
{
	return example0();
}
