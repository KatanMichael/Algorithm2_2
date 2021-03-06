#include "stdafx.h"

#include <iostream>
using namespace std;

void devideDogsToWalkers(int* arrOfDogs, int numberOfDogs, int numberOfWalkers);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void swap(int*, int* b);

class Distance
{
public:
	int i;
	int distanceToNext;
};



void main()
{
	int numberOfWalkers;
	int numberOFDogs;


	cout << "Enter How Many Dogs: " << endl;
	cin >> numberOFDogs;

	int *arrOfDogs = new int[numberOFDogs];

	cout << "Enter " << numberOFDogs << " Dogs Size" << endl;


	for (int i = 0; i < numberOFDogs; i++)
	{
		int temp;
		cin >> temp;
		arrOfDogs[i] = temp;
	}

	cout << "Printing Dogs :" << endl << endl;

	for (int i = 0; i < numberOFDogs; i++)
	{
		cout << arrOfDogs[i] << ", ";
	}

	quickSort(arrOfDogs, 0, numberOFDogs-1);


	devideDogsToWalkers(arrOfDogs, numberOFDogs, 4);

	system("pause");
}


void devideDogsToWalkers(int* arrOfDogs, int numberOfDogs, int numberOfWalkers)
{
	Distance *arrOfDistance = new Distance[numberOfDogs];

	arrOfDistance[0].i = 0;
	arrOfDistance[0].distanceToNext = 0;


	for (int i = 1; i < numberOfDogs; i++)
	{
		arrOfDistance[i].i = i;
		arrOfDistance[i].distanceToNext = (arrOfDogs[i] - arrOfDogs[i - 1]);
	}

	cout << "Printing Distance" << endl;
	for (int i = 0; i < numberOfDogs; i++)
	{
		cout << arrOfDistance[i].distanceToNext << ", ";
	}

}


//QuickSort Methods

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void swap(int* a, int* b)
{
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}