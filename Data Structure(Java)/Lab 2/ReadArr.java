// Write a program to read and display n numbers using an array.

import java.util.Scanner;

public class ReadArr {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter n :");
        int n = sc.nextInt();
        int[] arr = new int[n];

        for(int i = 0; i < n; i++){
            System.out.println("Enter number at "+i);
            arr[i] = sc.nextInt();
        }

        for(int i = 0; i < n; i++){
            if(i == n - 1){
                System.out.print(arr[i]);
            }
            else{
                System.out.print(arr[i]+",");
            }
        }

        sc.close();
    }
}
