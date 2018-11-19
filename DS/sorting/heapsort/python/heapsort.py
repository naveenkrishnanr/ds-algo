def minheapify(arr,rootIndex):
    left = 2 * rootIndex + 1;
    right = 2 * (rootIndex + 1);
    index = rootIndex;

    if left < len(arr) and arr[left] < arr[index]:
        index = left;
    if right < len(arr) and arr[right] < arr[index]:
        index = right;

    if index != rootIndex:
        temp = arr[index];
        arr[index] = arr[rootIndex];
        arr[rootIndex] = temp;
        minheapify(arr,index);


def buildheap(arr):
    for i in range(int(len(arr)/2),-1,-1):
        minheapify(arr,i);

def heapsort(arr): 
    res = [];
    buildheap(arr);
    for i in range(0,len(arr)):
        res.append(arr[0]);
        arr[0] = arr[len(arr)-1];
        arr=arr[:len(arr)-1];
        minheapify(arr,0);
    return res;