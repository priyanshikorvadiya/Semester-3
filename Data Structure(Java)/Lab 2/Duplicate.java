// Write a program to find whether the array contains a duplicate number or not.

import java.util.Scanner;

public class Duplicate {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of an array :");
        int n = sc.nextInt();
        int[] arr = new int[n];

        for(int i = 0; i < n ; i++){
            System.out.println("Enter array element at index "+i);
            arr[i] = sc.nextInt();
        }

        for(int i = 0; i < n; i++){
            for(int j = 1 ; j < n ; j++){
                if(arr[i] == arr[j]){
                    System.out.println("Duplicate !");
                    sc.close();
                    return;
                }
            }
        }
        sc.close();
    }
}
