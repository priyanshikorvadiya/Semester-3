// Read two 2x2 matrices and perform addition of matrices into third matrix and 
//print it 

import java.util.Scanner;

public class Add {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        int[][] A = new int[2][2];
        int[][] B = new int[2][2];
        int[][] Ans = new int[2][2];

        System.out.print("Enter elements for A:");
        for(int i = 0; i < 2 ; i++){
            for(int j = 0 ; j < 2; j++){
                System.out.print("A["+i+"]["+j+"]");
                A[i][j] = sc.nextInt();
            }
        }

        System.out.print("Enter elements for B:");
        for(int i = 0; i < 2 ; i++){
            for(int j = 0 ; j < 2; j++){
                System.out.print("B["+i+"]["+j+"]");
                B[i][j] = sc.nextInt();
            }
        }

        for(int i = 0; i < 2 ; i++){
            for(int j = 0 ; j < 2; j++){
                Ans[i][j] = A[i][j] + B[i][j];
            }
        }

        System.out.print("Addition :");
        for(int i = 0; i < 2 ; i++){
            for(int j = 0 ; j < 2; j++){
                System.out.println(Ans[i][j]);
            }
        }

        sc.close();
    }
}
