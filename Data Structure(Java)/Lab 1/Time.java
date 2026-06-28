//WAP to convert seconds into hours, minutes & seconds and print in HH:MM:SS 
//[e.g. 10000 seconds mean 2:46:40 (2 Hours, 46 Minutes, 40 Seconds)]. 

import java.util.Scanner;

public class Time {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Seconds:");
        int st = sc.nextInt();

        int hours = st / 3600;
        int mins = (st % 3600) / 60;
        int secs = st % 60;

        System.out.println(hours+":"+mins+":"+secs);

        sc.close();
    }
}
