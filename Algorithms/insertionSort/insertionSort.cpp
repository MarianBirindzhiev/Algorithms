#include <iostream>
#include <vector>
#include <string>

void InsertionSort(int arr[], int n)
{
	int j,key;
	for (size_t i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j>=0 && arr[j]>key)
		{
			arr[j + 1] = arr[j]; 
			j--;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	int a[]{ 1,5,2,6,8,2,7,7 };
	InsertionSort(a, 8);
	for (auto b : a)
		std::cout << b << ' ';
}


