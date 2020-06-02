def countingSort(arr):
    length = len(arr)
    output = [0]* length
    temp = [0]*100

    for i in range(0, length):
        temp[arr[i]] += 1
    
    for i in range(1, 100):
        temp[i] += temp[i - 1]
    
    for i in range((length - 1),-1, -1):
        output[temp[arr[i]] - 1] = arr[i]
        temp[arr[i]] -= 1

    return output    

def main():
    arr = [10,9,8,7,6,5,4,3,2,1]
    arr = countingSort(arr)
    print(arr)


if __name__ == '__main__':
    main()