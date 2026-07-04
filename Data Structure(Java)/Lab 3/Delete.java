// Write a program to delete a number from an array that is already sorted in an 
//ascending order. 

import java.util.Scanner;

public class Delete {
    public static void main(String[] args) {
         
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of an array :");
        int n = sc.nextInt();
        int[] arr = new int[n];

        for(int i = 0 ; i < n ; i++){
            System.out.println("Enter array element at "+i);
            arr[i] = sc.nextInt();
        }

        System.out.println("Final array :");
        for(int i = 0; i < n ; i++){
            if(i == n - 1){
                System.out.print(arr[i]);
            }
            else{
                System.out.print(arr[i]+",");
            }
        }

        System.out.print("Enter element you want to delete :");
        int ele = sc.nextInt();

        int index = n;

        for(int i = 0 ; i < n;  i++){
            if(arr[i] == ele){
                index = i;
                break;
            }
        }

        if(index < n){
            for(int i = index; i < n - 1; i++){
                arr[i] = arr[i + 1];
            }

            n--;

            for(int i = 0; i < n ; i++){
                if(i == n - 1){
                    System.out.print(arr[i]);
                }
                else{
                    System.out.print(arr[i]+",");
                }
            }

        }
        else{
            System.out.println("Element not found!!");
        }

        sc.close();
    }
}
