//Write a program to calculate average of first n numbers.

import java.util.Scanner;
public class AvgArr {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter n :");
        int n = sc.nextInt();
        int[] arr = new int[n];
        int sum = 0;
        float avg = 0;

        for(int i = 0; i < n; i++){
            System.out.println("Enter number at "+i);
            arr[i] = sc.nextInt();
        }

        for(int i = 0; i < n; i++){
            sum += arr[i];
        }

        avg = sum / n;

        System.out.println(avg);

        sc.close();
    }
}

