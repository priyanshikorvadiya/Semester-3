// Write a program to insert a number in an array that is already sorted in an 
//ascending order. 

import java.util.Scanner;

public class Insert {
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

        System.out.println("Enter element you want to insert:");
        int val = sc.nextInt();

        int index = n;

        for(int i = 0; i < n; i++){
            if(val <= arr[i]){
                index = i;
                break;
            }
        }

        for(int i = n - 1 ; i >= index; i--){
            arr[i + 1] = arr[i];
        }

        arr[index] = val;
        n++;

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
