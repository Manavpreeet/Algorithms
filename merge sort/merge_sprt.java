import java.util.Scanner;

class merge_sort {
    static int n;

    static void merge(int arr[], int p, int q , int r){
        int n1 = q - p + 1;  
        int n2 = r - q;
        int L[] = new int[n1];
        int R[] = new int[n2]; 

        for(int i=0; i<n1; i++)
            L[i] = arr[p + i];

        for(int i=0; i<n2; i++)
            R[i] = arr[q + i + 1];

        int i = 0, j = 0, k = p;
            
        while( i < n1 && j < n2){
            if(L[i] <= R[i]){
                arr[k] = L[i];
                k++;
                i++;
            }
            else{ 
                arr[k] = R[j];
                k++;
                j++;
            }
        }

        while(i < n1)
            arr[k++] = L[i++];
            
        while(j < n2)
            arr[k++] = R[j++];
        
    }

    static void sort(int arr[],int  p, int r){
        if(p < r){
            int q = (p+r)/2;
            sort(arr, p, q);
            sort(arr, q + 1, r);
            merge(arr, p, q, r);
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        n = input.nextInt();
        int arr[] = new int[n];

        for(int i=0; i<n; i++)
            arr[i] = input.nextInt();

        sort(arr, 0, n-1);
        
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}