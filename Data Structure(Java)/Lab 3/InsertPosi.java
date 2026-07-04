//Write a program to insert a number at a given location in an array. 

import java.util.Scanner;

public class InsertPosi{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of an array :");
        int n = sc.nextInt();
        int[] arr = new int[n + 1];//Because java has fixed sized array its size can't be changed

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

        System.out.println("Enter position where you want to insert element(0 - "+(n - 1)+") :");
        int posi = sc.nextInt();

        System.out.println("Enter element you want to insert:");
        int val = sc.nextInt();

        for(int i = n - 1; i >= posi ; i--){
               arr[i + 1] = arr[i];
        }

        arr[posi] = val;
        n++;//So that it will print all elements

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