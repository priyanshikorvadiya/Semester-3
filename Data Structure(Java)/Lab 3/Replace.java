// WAP to replace lowercase characters by uppercase & vice-versa in a user 
//specified string. 

import java.util.Scanner;

public class Replace {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter name :");
        String s = sc.next();

        // 2. Use StringBuilder for efficient string modification
        StringBuilder result = new StringBuilder();

        for(int i = 0 ; i < s.length(); i++){
            char ch = s.charAt(i);

            if(Character.isUpperCase(ch)){
                result.append(Character.toLowerCase(ch));
            }
            else if(Character.isLowerCase(ch)){
                result.append(Character.toUpperCase(ch));
            }
            else{
                result.append(ch);
            }
        }

        System.out.println(result.toString());

        sc.close();
    }
}
