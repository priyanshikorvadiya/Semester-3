// WAP to print Pascal triangle. 

import java.util.Scanner;

public class Pascal {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of rows :");
        int n = sc.nextInt();

        int[][] arr = new int[n][n];
        
        for(int i = 0; i < n; i++){
            for(int k = 0; k < n - 1; k++){
                System.out.print(" ");
            }
            for(int j = 0 ; j <= i ; j++){
                if(j == 0 || j == i){
                    arr[i][j] = 1;
                }
                else{
                    arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
                }
                System.out.print(arr[i][j]);
            }
            System.out.println();
        }
        
        sc.close();
    }
}
