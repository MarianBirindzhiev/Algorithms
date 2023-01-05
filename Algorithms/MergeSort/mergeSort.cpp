#include <vector>
#include <string>
#include <iostream>

void merge(std::vector<int>& arr,int left, int mid, int right)
{
    int rightArraySize = right - mid;
    int leftArraySize =mid-left+1;

    int* leftArray = new int[leftArraySize];
    int* rightArray = new int[rightArraySize];

    for (size_t i = 0; i < leftArraySize; i++)
        leftArray[i] = arr[left + i];

    for (size_t i = 0; i < rightArraySize; i++)
        rightArray[i] = arr[mid + 1 + i];

    int lIndex = 0, rIndex = 0, arrIndex = left;

    while (lIndex<leftArraySize && rightArraySize>rIndex)
    {
        if (leftArray[lIndex] > rightArray[rIndex])
            arr[arrIndex++] = rightArray[rIndex++];
        else
            arr[arrIndex++] = leftArray[lIndex++];
    }

    while(lIndex<leftArraySize)
        arr[arrIndex++] = leftArray[lIndex++];

    while(rIndex<rightArraySize)
        arr[arrIndex++] = rightArray[rIndex++];

    delete[] leftArray;
    delete[] rightArray;

}

void mergeSort(std::vector<int>& inputArray, int begin, int end)
{
    if (begin >= end)
        return;

    int mid = (begin + end) / 2;
    mergeSort(inputArray, begin, mid);
    mergeSort(inputArray, mid + 1, end);
    merge(inputArray, begin, mid, end);
}


int main()
{
    std::vector<int> A{ 12,2,24,5,5,61,17,19 };
    mergeSort(A, 0, A.size() - 1);
    for (size_t i = 0; i < A.size() - 1; i++)
    {
        std::cout << A[i] << ' ';
    }

}