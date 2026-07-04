// Read two matrices, first 3x2 and second 2x3, perform multiplication operation 
//and store result in third matrix and print it.

import java.util.Scanner;
public class Multi {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[][] A = new int[3][2];
        int[][] B = new int[2][3];
        int[][] Ans = new int[3][3];

        System.out.print("Enter elements for A:");
        for(int i = 0; i < 3 ; i++){
            for(int j = 0 ; j < 2; j++){
                System.out.print("A["+i+"]["+j+"]");
                A[i][j] = sc.nextInt();
            }
        }

        System.out.print("Enter elements for B:");
        for(int i = 0; i < 2 ; i++){
            for(int j = 0 ; j < 3; j++){
                System.out.print("B["+i+"]["+j+"]");
                B[i][j] = sc.nextInt();
            }
        }

        for(int i = 0; i < 3 ; i++){
            for(int j = 0 ; j < 3; j++){
                Ans[i][j] = 0;
                for(int k = 0 ; k < 2;k++){
                    Ans[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        System.out.print("Multiplication :");
        for(int i = 0; i < 3 ; i++){
            for(int j = 0 ; j < 3; j++){
                System.out.println(Ans[i][j]);
            }
        }

        sc.close();
    }
}
