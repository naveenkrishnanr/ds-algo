#include <iostream>
#include <algorithm>

using namespace std;

int values[100001];
int weights[100001];
int noOfElements = 0;

void idealKnapsack(int **matrix, int maxWeight, int position, int weight);

int main(int argc, char *argv[])
{
    cin>>noOfElements;

    int **knapSackMatrix = new int*[1000];
    for(int i = 0;i<1000;i++)
    {
        knapSackMatrix[i] = new int[2000];
    }

    int maxWeight = 0;
    for(int i = 0;i < noOfElements; i++)
    {
        cin>>weights[i];
        cin>>values[i];
        maxWeight += weights[i];
    }

    idealKnapsack(knapSackMatrix,maxWeight,0,0);

    for(int i = 1;i<maxWeight;i++)
    {
        cout<<knapSackMatrix[noOfElements-1][i]<<" ";
    }

    return 0;
}

void idealKnapsack(int **matrix,int maxWeight,int position,int weight)
{
    if(weight > maxWeight)
    {
        idealKnapsack(matrix,maxWeight,position+1,0);
        return;
    }

    if(position == noOfElements)
    {
        return;
    }

    if(weights[position] > weight)
    {
        if(position == 0)
        {
            matrix[position][weight] = 0;
            idealKnapsack(matrix,maxWeight,position,weight+1);
            return;
        }

        matrix[position][weight] = matrix[position-1][weight];
        idealKnapsack(matrix,maxWeight,position,weight+1);
        return;
    }
    else
    {
        if(position == 0)
        {
            matrix[position][weight] = values[position];
            idealKnapsack(matrix,maxWeight,position,weight+1);
            return;
        }

        int value = std::max(matrix[position-1][weight-weights[position]]+values[position],matrix[position-1][weight]);
        matrix[position][weight] = value;
        idealKnapsack(matrix,maxWeight,position,weight+1);
    }
}

//brute force approach
//int knapsack(int *weight,int *value,int noOfElements,int max,int itemsWeight,int itemsValue);
//int* createCopyWithoutItem(int *array,int noOfElements,int position);

//int main(int argc, char *argv[])
//{
//    int noOfElements;
//    int values[100001];
//    int weights[100001];

//    cin>>noOfElements;

//    int maxWeight = 0;
//    for(int i = 0;i < noOfElements; i++)
//    {
//        cin>>weights[i];
//        cin>>values[i];
//        maxWeight += weights[i];
//    }

//    for(int j=0;j<maxWeight;j++)
//    {
//        cout<<knapsack(weights,values,noOfElements,j+1,0,0)<<" ";
//    }

//    return 0;
//}


//int knapsack(int *weight,int *value,int noOfElements,int max,int itemsWeight,int itemsValue)
//{
//    int maxValue = itemsValue;
//    if(noOfElements == 0)
//    {
//        return maxValue;
//    }

//    for(int i = 0; i < noOfElements ; i++)
//    {
//        if(weight[i]+itemsWeight > max)
//            continue;

//        int *weightCopy = createCopyWithoutItem(weight,noOfElements,i);
//        int *valueCopy  = createCopyWithoutItem(value,noOfElements,i);

//        int iValue = knapsack(weightCopy,valueCopy,noOfElements-1,max,itemsWeight+weight[i],itemsValue+value[i]);
//        if(maxValue < iValue)
//        {
//            maxValue = iValue;
//        }

//        delete []weightCopy;
//        delete []valueCopy;
//    }

//    return maxValue;
//}

//int* createCopyWithoutItem(int *array,int noOfElements,int position)
//{
//    int *arrayCopy = new int[100000];
//    for(int i = 0;i<noOfElements;i++)
//    {
//        if(i==position)
//            continue;
//        arrayCopy[i]=array[i];
//    }

//    return arrayCopy;
//}
