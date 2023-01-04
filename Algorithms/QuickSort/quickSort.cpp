#include <iostream>
#include <vector>
#include <string>

int partitionIndex(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = count + start;
    std::swap(arr[pivotIndex], arr[start]);

    int low = start;
    int high = end;

    while (low<pivotIndex && high>pivotIndex)
    {
        while (arr[low] <= pivot)
            ++low;

        while (arr[high] > pivot)
            --high;

        if (low<pivotIndex && high>pivotIndex)
            std::swap(arr[low++], arr[high--]);
    }
    return pivotIndex;
}

void QuickSort(int arr[], int start, int end)
{
    if (start >= end)return;

    int pIndex = partitionIndex(arr, start, end);
    QuickSort(arr, start, pIndex - 1);
    QuickSort(arr, pIndex + 1, end);
}

int main()
{
    int a[]{ 1,5,2,6,8,2,7,7 };
    QuickSort(a, 0, 7);
    for (auto b : a)
        std::cout << b << ' ';
}


