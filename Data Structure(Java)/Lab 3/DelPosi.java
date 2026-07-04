//Write a program to delete a number from a given location in an array. 

import java.util.Scanner;

public class DelPosi{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of an array :");
        int n = sc.nextInt();
        int[] arr = new int[n];

        for(int i = 0 ; i < n ; i++){
            System.out.println("Enter array element     `1at "+i);
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

        System.out.println("Enter position where you want to delete element(0 - "+(n - 1)+") :");
        int posi = sc.nextInt();

        for(int i = posi; i < n - 1 ; i++){
               arr[i] = arr[i + 1];
        }

        n--;//So that it will print all elements

        for(int i = 0 ; i < n ; i++){
            if(i == n - 1){
                System.out.println(arr[i]);
            }
            else{
                System.out.print(arr[i]+",");
            }
        }

        sc.close();
    }
}