def insertion_sort(list):

    for j in range(1, len(list)):
        i = j- 1
        key = list[j]

        while i >= 0 and list[i] > key:
            list[i+1] = list[i]
            i = i - 1
        list[i+1] = key
    
def main():
    list = []
    

    n = int(input("Enter number of elements: "))

    for i in range(0,n):
        list.append(int(input()))

    insertion_sort(list)
    print(list)

if __name__ == "__main__":
    main()