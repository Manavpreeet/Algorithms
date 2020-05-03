import java.util.Scanner;

class insertion_sort{

    static int n;

    static void sort(int arr[]){
        
        for(int i=1; i<n; i++){
            int j = i - 1;
            int key = arr[i];
            while(j >= 0 && arr[j] > key){
                arr[ j+1 ] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }

    }

    static void display(int arr[]){
        
        for(int i=0; i<n; i++)
            System.out.print(arr[i] + " ");
        System.out.println();

    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        n = input.nextInt();
        int arr[] = new int[n];

        for(int i=0; i<n; i++)
            arr[i] = input.nextInt();
        
        // insertion_sort obj = insertion_sort();
        sort(arr);
        display(arr);

    }
}