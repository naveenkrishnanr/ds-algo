#include <iostream>

using namespace std;

void insertionSort(int *a, int length) {

    for( int i = 1; i < length; i++)
    {
        for( int j = 0; j < i;j++ )
        {
            if(a[i] > a[j])
            {
                continue;
            }

            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}

int main(int argc, char *argv[])
{
    int array[1000];
    int n;

    std::cin >> n;
    for(int i = 0; i < n;i++)
    {
        std::cin >> array[i];
    }

    insertionSort(array,n);

    for(int i = 0; i < n;i++)
    {
        std::cout << array[i] << " ";
    }

    return 1;
}
