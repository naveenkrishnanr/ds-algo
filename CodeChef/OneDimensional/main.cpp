#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int,int> pairs;

int main(int argc, char *argv[])
{
    int t;
    scanf("%d",&t);

    for(int i = 0;i< t;i++)
    {
        int n;
        scanf("%d",&n);
        vector<pairs> kingdoms;
        int leftExtreme = 100001;

        for(int j = 0;j<n;j++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            kingdoms.push_back(pairs(r,l));

            if(leftExtreme > l)
            {
                leftExtreme = l;
            }
        }

        std::sort(kingdoms.begin(),kingdoms.end());

        leftExtreme--;
        int count = 0;
        for(int k =0;k<n;k++)
        {
            if(leftExtreme < kingdoms[k].second)
            {
                count++;
                leftExtreme = kingdoms[k].first;
            }
        }

        printf("%d\n",count);
    }

    return 0;
}
