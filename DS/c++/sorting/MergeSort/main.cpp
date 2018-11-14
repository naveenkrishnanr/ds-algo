#include <iostream>

#define MAX 65536

using namespace std;

void merge(int *arr,int startIndex,int endIndex,int middle);
void mergeSort(int *arr,int startIndex,int endIndex)
{
    if(startIndex == endIndex)
    {
        return;
    }

    int middle = (startIndex+endIndex)/2;
    mergeSort(arr,startIndex,middle);
    mergeSort(arr,middle+1,endIndex);
    merge(arr,startIndex,endIndex,middle);
}

void merge(int *arr,int startIndex,int endIndex,int middle)
{
    int left[1000];
    int right[1000];
    for(int i = startIndex; i <= endIndex; i++)
    {
        if(i<=middle)
        {
            left[i-startIndex] = arr[i];
            continue;
        }

        right[i-(middle+1)] = arr[i];
    }

    left[middle-startIndex + 1] = MAX;
    right[endIndex-middle] = MAX;

    int j=0,k = 0;
    for(int i = startIndex;i<=endIndex;i++)
    {
        if(left[j] < right[k])
        {
            arr[i] = left[j++];
            continue;
        }

        arr[i] = right[k++];
    }
}

int main()
{
    int array[1000];
    int n;

    std::cin >> n;
    for(int i = 0; i < n;i++)
    {
        std::cin >> array[i];
    }

    mergeSort(array,0,n-1);

    for(int i = 0; i < n;i++)
    {
        std::cout << array[i] << " ";
    }

    return 0;
}
