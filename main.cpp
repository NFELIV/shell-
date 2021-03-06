// №13 Сортировка Хоара с простым слиянием 

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <omp.h>
#include <ctime>

using namespace std;

void CreateArray(double arr[], int lenght) //Генерация 
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < lenght; i++)
	{
		arr[i] = rand() % 10;
	}
}

void PrintArray(double* arr, int size) //Печать 
{
	if (size < 20)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i]<< " ";
		}
	}
	return;
}

void QuickSort(int length, double array[]) //Сортировка
{
	int i, j, step;
	double tmp;
	for (step = length / 2; step > 0; step /= 2)
		for (i = step; i < length; i++) 
		{
			tmp = array[i];
			for (j = i; j >= step; j -= step) 
			{
				if (tmp < array[j - step])
					array[j] = array[j - step];
				else
					break;
			}
			array[j] = tmp;
		}
}

int main(int argc, char * argv[]) 
{
	double size;
	double array[100000];
	double time = 0;
	cout << "Enter num's element's in array: ";
	cin >> size;
	CreateArray(array, size);
	cout << "The Generated array: ";
	PrintArray(array, size);
	cout << endl;
	time = clock();
	QuickSort(size, array);
	time = (clock() - time) / static_cast<double>(CLOCKS_PER_SEC);
	cout << "Array after QuickSort: ";
	PrintArray(array, size);
	cout << endl;
	cout << "Sequence version time: " << time << endl;
	delete[] array;
	return 0;
}