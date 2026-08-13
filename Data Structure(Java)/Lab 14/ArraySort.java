//  You have an array A of integers of size N, an array B (initially empty) and a stack 
// S (initially empty). You are allowed to do the following operations: 
 
//  Take the first element of array A and push it into S and remove it from A. 
//  Take the top element from stack S, append it to the end of array B and 
// remove it from S. 
 
// You have to tell if it possible to move all the elements of array A to array B using 
// the above operations such that finally the array B is sorted in ascending order. 
 
// Input Format : 
//  First line will contain T, number of testcases. Then the testcases follow. 
//  First line of each testcase contains a single integer N. 
//  Second line of each testcase contains N distinct integers : A1,A2...AN. 
 
// Output Format : 
// For each testcase, if it possible to move all the elements of array A to array B 
// using the above operations such that finally, the array B is sorted in ascending 
// order, print "YES" (without quotes), else print "NO" (without quotes).

import java.util.Scanner;
import java.util.Arrays;

public class ArraySort {
    
    static void Solve(Scanner sc){
       
        System.out.println("Enter number of digits :");
        int n = sc.nextInt();

        int[] A = new int[n];
        int[] sorted_A = new int[n];
        int[] S = new int[n];

        System.out.print("Enter array elements :");
        for(int i = 0 ; i < n; i++){
            A[i] = sc.nextInt();
            sorted_A[i] = A[i];
        }

        Arrays.sort(sorted_A);

        int top = -1;
        int expected_idx = 0;

        for(int i = 0 ; i < n ; i++){
            S[++top] = A[i];

            while (top >= 0 && S[top] == sorted_A[expected_idx]) {
                top--;
                expected_idx++;
            }
        }

        if(top == -1){
            System.out.println("Yes");
        }
        else{
            System.out.println("No");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number of test cases:");
        int T = sc.nextInt();

        while(T-- > 0){
            Solve(sc);
        }

        sc.close();
    }
}
