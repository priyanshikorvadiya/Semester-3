// Write a program to merge two unsorted arrays.

import java.util.Arrays;
import java.util.Scanner;

public class MergeArr {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of an array1 :");
        int n1 = sc.nextInt();
        int[] arr1 = new int[n1];

        for(int i = 0 ; i < n1 ; i++){
            System.out.println("Enter array1 element at "+i);
            arr1[i] = sc.nextInt();
        }

        System.out.println("Final array :");
        for(int i = 0; i < n1 ; i++){
            if(i == n1 - 1){
                System.out.print(arr1[i]);
            }
            else{
                System.out.print(arr1[i]+",");
            }
        }

        System.out.println();

        System.out.print("Enter size of an array2 :");
        int n2 = sc.nextInt();
        int[] arr2 = new int[n2];

        for(int i = 0 ; i < n2 ; i++){
            System.out.println("Enter arr2ay element at "+i);
            arr2[i] = sc.nextInt();
        }

        System.out.println("Final array :");
        for(int i = 0; i < n2 ; i++){
            if(i == n2 - 1){
                System.out.print(arr2[i]);
            }
            else{
                System.out.print(arr2[i]+",");
            }
        }

        System.out.println();

        int[] Arr = new int[n1 + n2];

        System.arraycopy(arr1, 0, Arr, 0, n1);
        System.arraycopy(arr2, 0, Arr, n1, n2);

        System.out.println("Merged Array :"+Arrays.toString(Arr));

        sc.close();
    } 
}
