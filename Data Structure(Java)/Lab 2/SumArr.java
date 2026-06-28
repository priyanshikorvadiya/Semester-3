// Write a program to calculate sum of numbers from m to n.

import java.util.Scanner;
public class SumArr {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter n :");
        int n = sc.nextInt();
        int[] arr = new int[n];
        int sum = 0;

        for(int i = 0; i < n; i++){
            System.out.println("Enter number at "+i);
            arr[i] = sc.nextInt();
        }

        for(int i = 0; i < n; i++){
            sum += arr[i];
        }

        System.out.println(sum);

        sc.close();
    }
}
