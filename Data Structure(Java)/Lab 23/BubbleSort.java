// Write a program to implement Bubble using Array. 

import java.util.Scanner;

public class BubbleSort {
    static void Bubblesort(int arr[], int n){
        for(int i = 0 ; i < n - 1 ; i++){

            int count = 0;

            for(int j = 0 ; j < n - i - 1 ; j++){
                if(arr[j] > arr[j + 1]){
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;

                    count = 1;
                }
            }

            if(count == 0){
                break;
            }
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

        Bubblesort(arr, n);

        System.out.println("Sorted array:");
        for(int i = 0; i < n; i++){
            System.out.print(arr[i] + " ");
        }

        sc.close();
    }
}
