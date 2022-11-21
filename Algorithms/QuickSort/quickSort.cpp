#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


template<typename T>
int partition(T* passedArray, int low, int high)
{
	int pivot = passedArray[high];
	int smallerElementIndex = low - 1;
	for (size_t j = low; j <= high-1; j++)
	{
		if (passedArray[j]<pivot)
		{
			smallerElementIndex++;
			std::swap(passedArray[smallerElementIndex], passedArray[j]);
		}
	}
	std::swap(passedArray[smallerElementIndex + 1], passedArray[high]);
	return (smallerElementIndex + 1);
}

template<typename T>
void quickSort(T* passedArray, int low, int high)
{
	if (low < high)
	{
		int partitioningIndex = partition(passedArray, low, high);
		quickSort(passedArray, low, partitioningIndex - 1);
		quickSort(passedArray, partitioningIndex + 1, high);
	}
}

int main()
{

}


