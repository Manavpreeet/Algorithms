def countingSort(arr, exp):
    length = len(arr)
    output = [0]* length
    temp = [0]*1000

    for i in range(0, length):
        index = (arr[i]/exp)
        temp[(index)%10] += 1
    
    for i in range(1, 100):
        temp[i] += temp[i - 1]
    
    for i in range((length - 1),-1, -1):
        index = (arr[i]/exp)
        output[ temp[ (index)%10 ] - 1] = arr[i]
        temp[ (index)%10 ] -= 1
    for i in range(0, len(arr)):
        arr[i] = output[i]


def radixSort(arr):
    maximum = max(arr)
    
    exp = 1
    while maximum/exp > 0:
        countingSort(arr, exp)
        exp *= 10

def main():
    arr = [10,9,8,7,6,5,4,3,2,1]
    radixSort(arr)
    print(arr)


if __name__ == '__main__':
    main()