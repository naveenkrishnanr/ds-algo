#include <stdio.h>
#include <math.h>





void quickSort( int a[], int l, int r)
{
    int j;

    if( l < r )
    {
        // divide and conquer
        j = partition( a, l, r);
        quickSort( a, l, j-1);
        quickSort( a, j+1, r);
    }

}



int partition( int a[], int l, int r) {
    int pivot, i, j, t;
    pivot = a[l];
    i = l; j = r+1;

    while( 1)
    {
        do ++i; while( a[i] <= pivot && i <= r );
        do --j; while( a[j] > pivot );
        if( i >= j ) break;
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
    t = a[l]; a[l] = a[j]; a[j] = t;
    return j;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while (0<t) {
        int n;
        long long int sum = 0;
        int max[100000];
        int arr[100000];
        int min[100000];
        scanf("%d",&n);
        int count = n;
        int iterator=0;
        while(0<n)
        {

            scanf("%d",&arr[iterator]);
            iterator++;
            n--;
        }
        quickSort(arr,0,iterator-1);
        n=count;
        iterator=0;
        while(n>0)
        {
            int a=arr[iterator];
            int j;

            max[iterator]=min[iterator]=a;


            for(j=0;j<=iterator;j++)
            {
                if(max[j]<a)
                    max[j]=a;
                if(min[j]>a)
                    min[j]=a;

                int f=(count-n+1);


                f=f-2-j;


                int tmax=max[j];
                int tmin=min[j];
                sum+=(tmax-tmin)*(pow(2,f));
            }
            iterator++;
            n--;
        }

        printf("%lld\n",sum);

        t--;
    }
    return 0;
}

