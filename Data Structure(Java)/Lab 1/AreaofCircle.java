//WAP to calculate area of a Circle (A = πr2). 

import java.util.Scanner;

public class AreaofCircle{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter radius:");
        int r = sc.nextInt();

        double area = Math.PI * r * r;

        System.out.println(area);

        sc.close();
    }
}