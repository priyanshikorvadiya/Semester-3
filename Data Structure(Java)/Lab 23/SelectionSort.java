//Write a program to implement Selection Sort using Array.

import java.util.Scanner;

public class SelectionSort {

    static void Selectionsort(int arr[], int n){
        for(int i = 0; i < n - 1 ; i++){
            int min_idx = i;

            for(int j = i + 1; j < n; j++){
                if(arr[j] < arr[min_idx]){
                    min_idx = j;
                }
            }

            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter size of an array:");
        int n = sc.nextInt();

        int[] arr = new int[n];

        System.out.println("Enter array elements:");
        for(int i = 0 ; i < n ; i++){
            arr[i] = sc.nextInt();
        }

        Selectionsort(arr, n);

        System.out.println("Sorted array:");
        for(int i = 0; i < n; i++){
            System.out.print(arr[i] + " ");
        }

        sc.close();
    }
}
