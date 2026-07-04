// Write a program to delete duplicate numbers from an array.

import java.util.Scanner;

public class DelDu {
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

        System.out.println();

        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                if(arr[i] == arr[j]){
                    for(int k = j ; k < n - 1 ; k++){
                        arr[k] = arr[k + 1];
                    }
                    n--;
                    j--;
                }
            }
        }

        for(int i = 0; i < n ; i++){
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
