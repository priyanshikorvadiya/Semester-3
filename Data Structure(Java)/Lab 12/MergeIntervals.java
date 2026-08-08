//  Merge Intervals Problem 
// Given a set of time intervals in any order, our task is to merge all overlapping 
// intervals into one and output the result which should have only mutually 
// exclusive intervals. 
 
// Sample Example-1: 
// Input: Intervals = {{1,3},{2,4},{6,8},{9,10}} 
// Output: {{1, 4}, {6, 8}, {9, 10}} 
// Explanation: Given intervals: [1,3],[2,4],[6,8],[9,10], we have only two overlapping 
// intervals here,[1,3] and [2,4]. Therefore we will merge these two and return [1,4],[6,8], 
// [9,10] 
 
// Sample Example-2: 
// Input: Intervals = {{6,8},{1,9},{2,4},{4,7}} 
// Output: {{1, 9}}

import java.util.Arrays;
import java.util.Scanner;

public class MergeIntervals {
    
    static int n = 100;
    static int[][] S = new int[n][2];
    static int top = -1;

    static int Compare(int[] a, int[] b){
        return Integer.compare(a[0], b[0]);
    }

    static void Merge(int[][] input,int m){
        if(m <= 0){
            return;
        }

        Arrays.sort(input, (a , b) -> Compare(a, b));

        top = 0;
        S[top][0] = input[0][0];
        S[top][1] = input[0][1];

        for(int i = 1; i < m ; i++){
            int start = input[i][0];
            int end = input[i][1];

            if(start <= S[top][1]){
                if(end > S[top][1]){
                    S[top][1] = end;
                }
            }
            else{
                top++;
                S[top][0] = start;
                S[top][1] = end;
            }
        }

        System.out.println("--Result--");
        for(int i = 0 ;i <= top ; i++){
            System.out.print("{"+ S[top][0]+","+S[top][1] +"}" );
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter total numbers of intervals:");
        int m = sc.nextInt();

        if(m == 1 || m <= 0 || m > n){
            System.out.println("Invalid number!!");
            sc.close();
            return;
        }

        int[][] input = new int[m][2];

        System.out.println("Enter the intervals (start and end for each):");
        for(int j = 0 ; j < m; j++){
            if(sc.hasNextInt()){
                input[j][0] = sc.nextInt();
            }
            else{
                System.out.println("Invalid input!!");
                sc.close();
                return;
            }

            if(sc.hasNextInt()){
                input[j][1] = sc.nextInt();
            }
            else{
                System.out.println("Invalid input!!");
                sc.close();
                return;
            }
        }

        Merge(input, m);

        sc.close();
    }
}
