//WAP to implement Insertion sort using array.

import java.util.Scanner;

public class InsertionSort {
    static void Insertionsort(int arr[], int n){
        int i = 1;

        while(i < n){
            int key = arr[i];
            int j = i - 1;

            while(j >= 0 && arr[j] > j ){
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
            i = i + 1;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter size of an array:");
        int n = sc.nextInt();

        int arr[] = new int[n];

        System.out.println("Enter array elements:");
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt(); 
        }

        Insertionsort(arr, n);

        System.out.println("Sorted array:");
        for(int i = 0; i < n; i++){
            System.out.print(arr[i] + " ");
        }

        sc.close();
    }
}
