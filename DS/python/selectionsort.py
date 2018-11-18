def sort(arr):
    for i in range(len(arr)):
        index = i;
        min = arr[index];
        for j in range(index,len(arr)):
            if not min > arr[j]:
                continue;
            min = arr[j];
            index = j;
        if index == i:
            continue;
        
        temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;

arr = [4,31,5,2,4];
sort(arr);
print(arr);