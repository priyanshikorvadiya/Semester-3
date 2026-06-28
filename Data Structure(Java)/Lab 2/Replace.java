// Read n numbers in an array then read two different numbers, replace 1st 
//number with 2nd number in an array and print its index and final array.

import java.util.Scanner;

public class Replace{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of an array :");
        int n = sc.nextInt();

        int[] arr = new int[n];

        System.out.print("Enter number 1 :");
        int n1 = sc.nextInt();

        System.out.print("Enter number 2 :");
        int n2 = sc.nextInt();
        int index = 0;

        for(int i = 0 ; i < arr.length; i++){
            System.out.println("Enter Element at "+i);
            arr[i] = sc.nextInt();
        }
        for(int i = 0 ; i < arr.length; i++){
            if(n1 == arr[i]){
                arr[i] = n2;
                index = i;
            }
        }

        System.out.println("Final Array :");
        for(int i = 0; i < arr.length ; i++){
            if(i == arr.length - 1){
                System.out.print(arr[i]);
            }
            else{
                System.out.print(arr[i]+",");
            }
        }
        System.out.println("Index of replacment :"+index);

        sc.close();
    }
}