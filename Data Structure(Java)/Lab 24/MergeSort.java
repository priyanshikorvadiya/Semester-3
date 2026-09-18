//WAP to implement Merge sort using array.

import java.util.Scanner;

public class MergeSort {
    static int max = 1000;
    static int a[] = new int[max];
    static int b[] = new int[max];

    static void Merge(int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        int k = low;
        
        while (i <= mid && j <= high) {
            if (a[i] <= a[j]) {
                b[k] = a[i];
                i = i + 1;
            } else {
                b[k] = a[j];
                j = j + 1;
            }
            k = k + 1;
        }
        
        while (i <= mid) {
            b[k] = a[i];
            i = i + 1;
            k = k + 1;
        }
        
        while (j <= high) {
            b[k] = a[j];
            j = j + 1;
            k = k + 1;
        }
        
        for (int x = low; x <= high; x++) {
            a[x] = b[x];
        }
    }

    static void Mergesort(int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            Mergesort(low, mid);
            Mergesort(mid + 1, high);
            Merge(low, mid, high);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter size of an array:");
        int n = sc.nextInt();
        
        if (n <= 0 || n > max) {
            System.out.println("Invalid size!");
            sc.close();
            return;
        }
        
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt(); 
        }
        
        Mergesort(0, n - 1);
        
        System.out.println("Sorted array elements:");
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        sc.close();
    }
}
