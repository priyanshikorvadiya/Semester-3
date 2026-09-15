// Write a program to implement a Binary Search using Array. (Iterative & 
// recursive)

import java.util.Scanner;

public class BinarySearch {

    //Iterative binarysearch function
    static int BinarySearchI(int arr[], int n, int x){
        int low = 0;
        int high = n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(arr[mid] == x){
                return mid;
            }

            if(arr[mid] < x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return -1;
    }

    //Recursive binarysearch function
    static int BinarySearchR(int arr[] , int low , int high , int x){

        if(low > high){
            return -1;
        }

        int mid = low + (high - low) / 2;

        if(arr[mid] == x){
            return mid;
        }

        if(arr[mid] < x){
            return BinarySearchR(arr , mid + 1 , high , x);
        }
        else{
            return BinarySearchR(arr , low , mid - 1 , x);
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

        System.out.println("Enter value to find:");
        int x = sc.nextInt();

        int index1 = BinarySearchI(arr , n , x);
        int index2 = BinarySearchR(arr , 0 , n - 1 , x);

        System.out.println("Value found at(Iterative approch) :"+ index1);
        System.out.println("Value found at(Recursive approch) :"+ index2);

        sc.close();
    }
}
