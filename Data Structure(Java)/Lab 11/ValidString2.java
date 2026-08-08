//Write a program to determine if an input character string is of the form aibi 
//where i >= 1 i.e., Number of ‘a’ should be equal to number of ‘b’. 

import java.util.Scanner;

public class ValidString2 {
    
    static int Match(String str){
        int i = 0;

        int Acount = 0;
        int Bcount = 0;

        while(i < str.length() && str.charAt(i) == 'a'){
            Acount++;
            i++;
        }

        if(Acount == 0){
            return 0;
        }

        while(i < str.length() && str.charAt(i) == 'b'){
            Bcount++;
            i++;
        }

        if(i == str.length()
              && Acount == Bcount){
            return 1;
        }
        return 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter string :");
        String str = sc.next();

        if(Match(str) == 1){
            System.out.println("String " +str + " is matched.");
        }
        else{
            System.out.println("String " +str + " is not matched.");
        }
        sc.close();
    }
}
