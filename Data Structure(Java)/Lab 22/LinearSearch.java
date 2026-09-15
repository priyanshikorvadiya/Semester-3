// Write a program to implement a Linear Search using Array.

import java.util.Scanner;

public class LinearSearch {

    static int Linearsearch(int arr[], int size, int x){
        for(int i = 0 ; i < size ; i++){
            if(arr[i] == x){
                return i;
            }
        }
        return -1;
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

        System.out.println("Enter value to find:");
        int x = sc.nextInt();

        int index = Linearsearch(arr, n, x);

        System.out.println("Value found at index :"+ index);

        sc.close();
    }
}
