//WAP to sort the N names in an alphabetical order. 

import java.util.Scanner;

public class SortName {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of names :");
        int n = sc.nextInt();
        String[] arr = new String[n];

        for(int i = 0 ; i < n ; i++){
            System.out.print("Enter word :");
            arr[i] = sc.next();
        }

        for(int i = 0 ; i < n - 1 ; i++){
            for(int j = 0 ; j < n - i - 1 ; j++){
                if(arr[j].compareTo(arr[j + 1]) > 0){
                    String temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            System.out.println(arr[i]);
        }

        sc.close();
    }
}
