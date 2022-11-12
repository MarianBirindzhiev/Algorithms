#include <iostream>
#include <vector>
#include <string>

template <typename T>
int binarySearchIterativeMethod(std::vector<T> sortedArray,const T& desiredElement)
{
    int leftIndex = 0;
    int rightIndex = sortedArray.size() - 1;
    int midIndex;
    while (leftIndex <= rightIndex)
    {
       midIndex = (leftIndex + rightIndex) / 2;
       if (sortedArray[midIndex] > desiredElement)
        {
            rightIndex = midIndex - 1;
        }
        else if (sortedArray[midIndex] < desiredElement)
        {
            leftIndex = midIndex + 1;
        }
        else
        {
            return midIndex;
        }
    }
    return -1;
}

template <typename T>
int binarySearchHelper(std::vector<T> sortedArray, const T& desiredElement,int leftIndex,int rightIndex)
{
    int midIndex;
    
    if (leftIndex>rightIndex)
    {
        return -1;
    }
    midIndex = (leftIndex + rightIndex) / 2;
    if (desiredElement <sortedArray[midIndex])
    {
        return binarySearchHelper(sortedArray, desiredElement, leftIndex, midIndex - 1);
    }
    else if (desiredElement > sortedArray[midIndex])
    {
        return binarySearchHelper(sortedArray, desiredElement, midIndex + 1, rightIndex);
    }
    else
    {
        return midIndex;
    }
}
template <typename T>
int binarySearchRecursiveMethod(std::vector<T> sortedArray,const T& desiredElement)
{
    int leftIndex = 0;
    int rightIndex = sortedArray.size() - 1;

    return binarySearchHelper(sortedArray, desiredElement, leftIndex, rightIndex);
}


int main()
{

}


