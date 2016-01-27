#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
using namespace std;
void quickSort(int*, int);
void printArray(int*, int);
void checkSort(int* , int);
void bucketSort(vector<int> arr);
void switchNums(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
int main()
{
	srand(time(NULL));
	const int ARR_SIZE = 10;
	vector<int> arr;
	for (int i = 0; i < ARR_SIZE; i++)
		arr.push_back(rand());
	bucketSort(arr);
	/*printArray(&(arr[0]),ARR_SIZE);
	quickSort(&(arr[0]), ARR_SIZE);
	printArray(&(arr[0]), ARR_SIZE);
	checkSort(&(arr[0]), ARR_SIZE);
	cin.get();*/
	return 0;
}
void quickSort(int* arr, int length)
{
	//printArray(&arr[0], length);
	int pivot = length-1;
	int i = 0;
	int j = length - 1;
	while (i != j)
	{
		while (arr[i] <= arr[pivot] && i != j)
			i++;
		while (arr[j] >= arr[pivot] && i != j)
			j--;
		switchNums(&arr[i], &arr[j]);
	}
	switchNums(&arr[pivot],&arr[i]);
	pivot = i;
	if (length-pivot > 2)
		quickSort(&(arr[pivot+1]),length-pivot-1);
	if (pivot > 1)
		quickSort(&(arr[0]), pivot);
}
void bucketSort(vector<int> arr)
{
	vector<int> buckets[] = { vector<int>(0), vector<int>(0), vector<int>(0), vector<int>(0), vector<int>(0), vector<int>(0), vector<int>(0), vector<int>(0), vector<int>(0), vector<int>(0), };
	// Scan and assign to buckets
	for (int c = 10; c < 100000; c *= 10)
	{
		for (int i = arr.size() - 1; i > 0; i--)
		{
			buckets[arr[i] % c / (c / 10)].push_back(arr[i]);
		}
		arr.clear();
		for (int x = 0; x < 10; x++)
		{
			for (int a = 0; a < buckets[x].size(); a++)
			{
				arr.push_back(buckets[x][a]);
			}
		}
	}
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
}
void printArray(int* arr, int length)
{
	cout << endl;
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
		if ((i + 1) % 13 == 0)
			cout << endl;
	}
	cout << endl;
}
void checkSort(int* arr, int length)
{
	bool good = true;
	for (int i = 1; i < length; i++)
	{
		if (arr[i - 1] > arr[i])
			good = false;
	}
	if (good)
		cout << endl << "ARRAY IS SORTED!" << endl;
}