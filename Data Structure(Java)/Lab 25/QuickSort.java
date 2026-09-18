// Write a program to implement Quick Sort using Array.

import java.util.Scanner;

public class QuickSort {

    static void Quicksort(int arr[], int LB, int UB){
        boolean Flag = true;

        if(LB < UB){
            int I = LB;
            int J = UB; // Fixed: Changed from UB + 1 to avoid out of bounds
            int key = arr[LB];

            while(Flag == true){
                // Fixed: Added I <= UB check to prevent checking past the array size
                while(I <= UB && arr[I] <= key){ 
                    I = I + 1;
                }
                
                // Fixed: Changed condition to >= to correctly handle values down to LB
                while(arr[J] > key){
                    J = J - 1;
                }

                if(I < J){
                    int temp = arr[I];
                    arr[I] = arr[J];
                    arr[J] = temp;
                }
                else{
                    Flag = false;
                }
            }

            int temp = arr[LB];
            arr[LB] = arr[J];
            arr[J] = temp;

            Quicksort(arr, LB, J - 1);
            Quicksort(arr, J + 1, UB);
        }
        return;
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

        Quicksort(arr, 0, n - 1);

        System.out.println("Sorted array:");
        for(int i = 0; i < n; i++){
            System.out.print(arr[i] + " ");
        }

        sc.close();
    }
}
