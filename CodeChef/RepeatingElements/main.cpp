#include <iostream>

using namespace std;

int main()
{
    int a[] = {1,2,2,1,1};
    int size = 5;
    int count = 0;
    int i=0;
    int j=0;
    while(i<size){
        i = j;
        j = i+1;
        while(a[i]==a[j]){
            count = count+1;
            cout<<"("<<a[i]<<","<<a[j]<<")"<<endl;
            a[i]=-1;
            a[j]=-1;
            i=i-1;
            while(a[i] == -1)
                i=i-1;
            j=j+1;
        }
    }
    cout<<"count "<<count<<endl;
    return 0;
}
