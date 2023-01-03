#include <iostream>
#include <vector>
#include <string>

void swapif(int& a, int& b)
{
	if (b < a)
		std::swap(a, b);
}

void BubbleSort(int unsortedArray[],int n)
{
	for (size_t i = 0; i < n-1; i++)
	{
		for (size_t j = 0; j < n-i-1; j++)
		{
			swapif(unsortedArray[j], unsortedArray[j + 1]);
		}
	}
}

int main()
{
	int a[]{ 1,5,2,6,8,2,7,7 };
	BubbleSort(a,8);
	for (auto b : a)
		std::cout << b<<' ';
}


