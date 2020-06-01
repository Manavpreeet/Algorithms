def partition(arr, low, high):
    i = low - 1
    pivot = arr[high]

    for j in range(low, high):
        if arr[j] < pivot:
            i = i + 1
            arr[i],arr[j] = arr[j],arr[i]
    arr[i + 1],arr[high] = arr[high], arr[i + 1]
    return (i+1)

def quickSort(arr, low, high):
    if low < high:
        pivot = partition(arr, low, high)
        quickSort(arr, low , pivot - 1)
        quickSort(arr, pivot + 1, high)
def main():
    arr = [10,9,8,7,6,5,4,3,2,1]
    quickSort(arr, 0, 9)
    print(arr)


if __name__ == '__main__':
    main()