#include "omp.h"
#include <iostream>
#include "submit.h"
#include "stdio.h"

using namespace std;

void vec_random_norm(float* rand_arr, int n)
{
	float min_v, max_v;

	#pragma omp single copyprivate(min_v, max_v)
	{
		min_v = rand_arr[0];
		max_v = rand_arr[0];
		for (int i = 1; i < n; i++)
		{
			if (min_v > rand_arr[i]) min_v = rand_arr[i];
			if (max_v < rand_arr[i]) max_v = rand_arr[i];
		}
	}

	int num_th = omp_get_thread_num();
	rand_arr[num_th] = (rand_arr[num_th] - min_v) / (max_v - min_v);

	Submit_test();
}