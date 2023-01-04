#include <iostream>
#include <vector>
#include <string>

void SelectionSort(int arr[], int n)
{
	int k, l;
	for (size_t i = 0; i < n-1; i++)
	{
		k = i;
		for (int j = i; j < n; j++)
		{
			if (arr[k]>arr[j])
			{
				k = j;
			}
		}
		std::swap(arr[k], arr[i]);
	}
}

int main()
{
	int a[]{ 1,5,2,6,8,2,7,7 };
	SelectionSort(a, 8);
	for (auto b : a)
		std::cout << b << ' ';
}


