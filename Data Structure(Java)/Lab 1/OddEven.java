//WAP to find whether a number is odd or even. 

import java.util.Scanner;

public class OddEven {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number:");
        int n = sc.nextInt();

        if(n % 2 == 0){
            System.out.println("Given number is even.");
        }
        else{
            System.out.println("Given number is odd.");
        }

        sc.close();
    }
}
