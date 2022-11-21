#include <vector>
#include <string>
#include <iostream>

template <typename T>
void merge(std::vector<T> array, const int leftIndex, const int midIndex, const int rightIndex)
{
    const int leftArrayCapacity = midIndex - leftIndex;
    const int rightArrayCapacity = rightIndex - midIndex + 1;

    int indexOfLeftArray = 0;
    int indexOfRightArray = 0;
    int indexOfMergedArray = leftIndex;

    T* leftArray = new T[leftArrayCapacity];
    T* rightArray = new T[rightArrayCapacity];

    for (size_t currentIndex = 0; currentIndex < leftArrayCapacity; currentIndex++)
    {
        leftArray[currentIndex] = array[currentIndex];
    }
    for (size_t currentIndex = 0; currentIndex < rightArrayCapacity; currentIndex++)
    {
        rightArray[currentIndex] = array[currentIndex];
    }

    while (indexOfLeftArray < leftArrayCapacity && indexOfRightArray < rightArrayCapacity)
    {
        T currentLeftArrayElement = leftArray[indexOfLeftArray];
        T currentRightArrayElement = rightArray[indexOfRightArray];
        if (currentLeftArrayElement <= currentRightArrayElement)
        {
            array[indexOfMergedArray] = currentLeftArrayElement;
            ++indexOfLeftArray;
        }
        else
        {
            array[indexOfMergedArray] = currentRightArrayElement;
            ++indexOfRightArray;
        }
        ++indexOfMergedArray;
    }

    while (indexOfLeftArray < leftArrayCapacity)
    {
        array[indexOfMergedArray] = leftArray[indexOfLeftArray];
        ++indexOfLeftArray;
        ++indexOfMergedArray;
    }
    while (indexOfRightArray < rightArrayCapacity)
    {
        array[indexOfMergedArray] = rightArray[rightIndex];
        ++indexOfRightArray;
        ++indexOfMergedArray;
    }

    delete[] leftArray;
    delete[] rightArray;

}

template <typename T>
void mergeSort(std::vector<T> inputArray, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    int midIndex = begin + (end - begin) / 2;
    mergeSort(inputArray, begin, midIndex);
    mergeSort(inputArray, midIndex + 1, end);
    merge(inputArray, begin, midIndex, end);
}


int main()
{
    std::vector<int> A{ 141,2,24,5,5,61,122,667 };
    mergeSort(A, 0, A.size() - 1);
    for (size_t i = 0; i < A.size() - 1; i++)
    {
        std::cout << A[i] << '\n';
    }

}