#include "GaussSeidel.h"
#include "omp.h"
#include <iomanip>
#include <cstdlib>
#include <iostream>

using namespace std;


int Calc_par(double** u, double** f, int N, double eps)
{

	double max = 0;
	double h = 1.0 / (N + 1);

	int IterCnt = 0; // Переменная хранящая количество выполненых итераций
	int BlockSize = 50; // Переменная отвечающая за размерность блока, для которого выполняется обработка
	int BlockCount; // Количество блоков

	if ((N) % BlockSize == 0)
	{
		BlockCount = (N) / BlockSize;

		do
		{
			IterCnt++;
			max = 0;
			int main_count = 0;
			bool flag = false;
			int IBstart = 0;
			int JBstart = 0;
			while (main_count < BlockCount * 2 - 1)
			{
				#pragma omp parallel for reduction(max:max)
				for (int IBlock = IBstart, JBlock = JBstart; JBlock >= IBstart; IBlock++, JBlock--)
				{
					for (int idx = 0; idx < BlockSize; idx++) // Проход по строчкам блока
					{
						for (int jdy = 0; jdy < BlockSize; jdy++) // Проход по столбцам блока
						{
							int i = 1 + IBlock * BlockSize + idx; // Вычисление глобального i индекса элемента
							int j = 1 + JBlock * BlockSize + jdy; // Вычисление глобального j индекса элемента
							double u0 = u[i][j];
							u[i][j] = 0.25 * (u[i - 1][j] + u[i + 1][j] // Расчет в соотвествии с формулами Гаусса-Зейделя
								+ u[i][j - 1] + u[i][j + 1] - h * h * f[i - 1][j - 1]);
							double d = abs(u[i][j] - u0); // Расчет модуля разности нового вычисленного значения неизвестной переменной и значения с предыдущей итераций 
							
							if (d > max) // Поиск максимальной ошибки
								max = d;
						}
					}
				}

				if (flag)
				{
					IBstart++;
				}
				else
				{
					JBstart++;
				}

				flag = JBstart == BlockCount - 1;
				main_count++;
			}
		}
		while (max > eps); // Цикл выполняется до тех пор пока максимум ошибки не будет меньше заданной точности
	}
	else
	{
		cout << "Error!!!" << endl;
	}


	// Здесь вы должны реализовать параллельный блочно-волновой алгоритм
	//if ((N) % BlockSize == 0)
	//{
	//	BlockCount = (N) / BlockSize;
	//
	//	void (*__work_with_block__)(const int&, const int&, const int&, double**, double**, const double&, double&, omp_lock_t*) =
	//		[](const int& _IBlock, const int& _JBlock, const int& _BlockSize, double** _u, double** _f,
	//			const double& _h, double& _max, omp_lock_t* _lock_max)->void
	//	{
	//		for (int idx = 0; idx < _BlockSize; idx++) // Проход по строчкам блока
	//		{
	//			for (int jdy = 0; jdy < _BlockSize; jdy++) // Проход по столбцам блока
	//			{
	//				int i = 1 + _IBlock * _BlockSize + idx; // Вычисление глобального i индекса элемента
	//				int j = 1 + _JBlock * _BlockSize + jdy; // Вычисление глобального j индекса элемента
	//				double u0 = _u[i][j];
	//				_u[i][j] = 0.25 * (_u[i - 1][j] + _u[i + 1][j] // Расчет в соотвествии с формулами Гаусса-Зейделя
	//					+ _u[i][j - 1] + _u[i][j + 1] - _h * _h * _f[i - 1][j - 1]);
	//				double d = abs(_u[i][j] - u0); // Расчет модуля разности нового вычисленного значения неизвестной переменной и значения с предыдущей итераций 
	//				omp_set_lock(_lock_max);
	//				if (d > _max) // Поиск максимальной ошибки
	//					_max = d;
	//				omp_unset_lock(_lock_max);
	//			}
	//		}
	//	};
	//
	//	omp_set_max_active_levels(2);
	//
	//	omp_lock_t* lock_max = new omp_lock_t;
	//	omp_init_lock(lock_max);
	//
	//	do
	//	{
	//		IterCnt++;
	//		max = 0;
	//		
	//		for (int main_count1 = 0; main_count1 < BlockCount; main_count1++)
	//		{
	//			for (int JBlock = main_count1; JBlock >= 0; JBlock--)
	//			{
	//				__work_with_block__(main_count1 - JBlock, JBlock, BlockSize, u, f, h, max, lock_max);
	//			}
	//		}

	//		for (int main_count2 = 1; main_count2 < BlockCount; main_count2++)
	//		{
	//			for (int IBlock = main_count2; IBlock < BlockCount; IBlock++)
	//			{
	//				__work_with_block__(IBlock, BlockCount - IBlock, BlockSize, u, f, h, max, lock_max);
	//			}
	//		}
	//	}
	//	while (max > eps); // Цикл выполняется до тех пор пока максимум ошибки не будет меньше заданной точности
	//
	//	omp_destroy_lock(lock_max);
	//	delete lock_max;
	//}
	//else
	//{
	//	cout << "Error!!!" << endl;
	//}

	// Здесь вы должны реализовать параллельный блочно-волновой алгоритм
	//if ((N) % BlockSize == 0)
	//{
	//	BlockCount = (N) / BlockSize;
	//	do
	//	{
	//		IterCnt++;
	//		max = 0;
	//		int main_count = 0;
	//		bool flag = false;
	//		int IBstart = 0;
	//		int JBstart = 0;
	//		while (main_count < BlockCount * 2 - 1)
	//		{
	//			for (int IBlock = IBstart, JBlock = JBstart; JBlock >= IBstart; IBlock++, JBlock--)
	//			{
	//				for (int idx = 0; idx < BlockSize; idx++) // Проход по строчкам блока
	//				{
	//					for (int jdy = 0; jdy < BlockSize; jdy++) // Проход по столбцам блока
	//					{
	//						int i = 1 + IBlock * BlockSize + idx; // Вычисление глобального i индекса элемента
	//						int j = 1 + JBlock * BlockSize + jdy; // Вычисление глобального j индекса элемента
	//						double u0 = u[i][j];
	//						u[i][j] = 0.25 * (u[i - 1][j] + u[i + 1][j] // Расчет в соотвествии с формулами Гаусса-Зейделя
	//							+ u[i][j - 1] + u[i][j + 1] - h * h * f[i - 1][j - 1]);
	//						double d = abs(u[i][j] - u0); // Расчет модуля разности нового вычисленного значения неизвестной переменной и значения с предыдущей итераций 
	//						if (d > max) // Поиск максимальной ошибки
	//							max = d;
	//					}
	//				}
	//			}
	//
	//			if (flag)
	//			{
	//				IBstart++;
	//			}
	//			else
	//			{
	//				JBstart++;
	//			}
	//
	//			flag = JBstart == BlockCount - 1;
	//			main_count++;
	//		}
	//	}
	//	while (max > eps); // Цикл выполняется до тех пор пока максимум ошибки не будет меньше заданной точности
	//}
	//else
	//{
	//	cout << "Error!!!" << endl;
	//}
	
	return IterCnt;
}
