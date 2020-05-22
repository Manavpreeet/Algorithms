def findMaximumCrossingSubarray(arr, low, mid, high):
    left_sum = -1000000000000
    total_sum = 0
    max_left = mid
    for i in range(mid, low, -1):
        total_sum = total_sum + arr[i]
        if total_sum > left_sum:
            left_sum = total_sum
            max_left = i
    max_right = mid+1
    total_sum = 0
    right_sum = -1000000000000
    for i in range(mid+1, high):
        total_sum = total_sum + arr[i]
        if total_sum > right_sum:
            right_sum = total_sum
            max_right = i
    return (max_left, max_right, left_sum + right_sum)

def findMaximumSubarray(arr, low, high):
    if high == low:
        return (low, high, arr[low])
    else:
        mid = (low + high)//2
        (left_low, left_high, left_sum) = findMaximumSubarray(arr, low, mid)
        (right_low, right_high, right_sum) = findMaximumSubarray(arr, mid+1, high)
        (cross_low, cross_high, cross_sum) = findMaximumCrossingSubarray(arr, low, mid, high)
        
        if left_sum >= right_sum and left_sum >= cross_sum:
            return (left_low, left_high, left_sum)
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return (right_low, right_high, right_sum)
        else:
            return (cross_low, cross_high, cross_sum)

        return max()

def main():
    arr = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
    # n = int(input("Enter number of elements: "))
    # for i in range(0,n):
    #     arr.append(int(input()))
    (start, end, sum) = findMaximumSubarray(arr, 0, 15)
    print ("Staring index: " + str(start))
    print ("Ending index: " + str(end))
    print ("Sum: " + str(sum)) 



if __name__ == "__main__":
    main()