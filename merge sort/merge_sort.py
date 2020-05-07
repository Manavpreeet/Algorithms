def merge(list, mid):

    L = list[ : mid]
    R = list[mid : ]

    i = j = k = 0

    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            list[k] = L[i]
            k = k + 1
            i = i + 1
        else:
            list[k] = R[j]
            k = k + 1
            j = j + 1

    while i < len(L):
        list[k] = L[i]
        k = k + 1
        i = i + 1

    while j < len(R):
        list[k] = R[j]
        k = k + 1
        j = j + 1


def merge_sort(list, p, r):
    if(p < r):
        q = (p+r)//2
        merge_sort(list, p, q)
        merge_sort(list, q+1, r)
        merge(list,q)

def main():
    list = []
    n = int(input("Enter number of elements: "))
    for i in range(0,n):
        list.append(int(input()))
    merge_sort(list, 0, n)
    print (list)

if __name__ == '__main__':
    main()
    