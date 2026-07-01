// Write a program to find position of the smallest number & the largest number 
//from given n numbers.

import java.util.Scanner;

public class MaxMin {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size");
        int n = sc.nextInt();
        int[] arr = new int[n];

        for(int i = 0 ; i < n;i++){
            System.out.print("Enter element at "+i);
            arr[i] = sc.nextInt();
        }

        int max = arr[0];
        int min = arr[0];

        for(int i = 0; i < n;i++){
            if(max < arr[i]){
                max = arr[i];
            }
        }

        for(int i = 0; i < n;i++){
            if(min > arr[i]){
                min = arr[i];
            }
        }

        System.out.println(max);
        System.out.println(min);

        sc.close();
    }
}
