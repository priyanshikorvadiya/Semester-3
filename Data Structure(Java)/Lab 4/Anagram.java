//  Design anagram game using array.  
//  Allow a user to enter N words and store it in an array.  
//  Generate a random number between 0 to N-1.  
//  Based on the random number generated display the word stored at that 
// index of an array and allow user to enter its anagram.  
//  Check whether the word entered by the user is an anagram of displayed 
// number or not and display an appropriate message.  
//  Given a word A and word B. B is said to be an anagram of A if and only if the 
// characters present in B is same as characters present in A, irrespective of 
// their sequence. For ex: “LISTEN” == “SILENT"

import java.util.Arrays;
import java.util.Scanner;

public class Anagram {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter no. of words:");
        int n = sc.nextInt();

        if(n <= 0){
            System.out.println("Invalid number !");
            sc.close();
            return;
        }

        String[] words = new String[n];

        System.out.println("Enter "+n+ "words in small letters :");
        for(int i = 0 ; i < n ; i++){
            words[i] = sc.next();
        }

        int score = 0;
        char choice;

        do{
            int random = (int)(Math.random() * n);

            String word = words[random];

            System.out.println("Enter Anagram for :"+word);

            System.out.print("Enter Anagram :");
            String[] user = new String[100];

            String userguess = sc.next();

            boolean isAnagram = false;

            for(int i = 0 ; i < userguess.length() ; i++){
                user[i] = String.valueOf(userguess.charAt(i));
            }

            if(words[random].length() == userguess.length()){

                char[] wordc = word.toCharArray();
                char[] userg = userguess.toCharArray();

                Arrays.sort(wordc);
                Arrays.sort(userg);

                    if(Arrays.equals(wordc, userg)){
                        isAnagram = true;
                    }
            }

            if(isAnagram){
                System.out.println("Hurray! Words are Anagram.");
                score +=10;
            }
            else{
                System.out.println("Oops!! Words are not Anagram.");
            }

            System.out.println("Your current score:"+score);
            System.out.println("Do you want to play another round(y/n):");
            choice = sc.next().toLowerCase().charAt(0);

        }while(choice == 'y');

        System.out.println("Final score :"+score);

        sc.close();
    }
}
