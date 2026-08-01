// //  Merge Intervals Problem 
// // Given a set of time intervals in any order, our task is to merge all overlapping 
// // intervals into one and output the result which should have only mutually 
// // exclusive intervals. 
 
// // Sample Example-1: 
// // Input: Intervals = {{1,3},{2,4},{6,8},{9,10}} 
// // Output: {{1, 4}, {6, 8}, {9, 10}} 
// // Explanation: Given intervals: [1,3],[2,4],[6,8],[9,10], we have only two overlapping 
// // intervals here,[1,3] and [2,4]. Therefore we will merge these two and return [1,4],[6,8], 
// // [9,10] 
 
// // Sample Example-2: 
// // Input: Intervals = {{6,8},{1,9},{2,4},{4,7}} 
// // Output: {{1, 9}}



#include <stdio.h>
#include <stdlib.h>

#define N 100

int S[N][2];
int top = -1;

int compare(const void *a, const void *b) {
    int *rowA = (int *)a;
    int *rowB = (int *)b;
    return rowA[0] - rowB[0];
}

void Merge(int input[][2], int m) {
    if (m <= 0){
        return;
    }

    qsort(input, m, sizeof(input[0]), compare);

    top = 0;
    S[top][0] = input[0][0];
    S[top][1] = input[0][1];

    for (int i = 1; i < m; i++) {
        int start = input[i][0];
        int end = input[i][1];

        if (start <= S[top][1]) {
            if (end > S[top][1]) {
                S[top][1] = end;
            }
        } 
        else {
            top++;
            S[top][0] = start;
            S[top][1] = end;
        }
    }

    printf("Result: ");
    for (int i = 0; i <= top; i++) {
        printf("{%d, %d} ", S[i][0], S[i][1]);
    }
    printf("\n");
}

void main() {
    int m;
    printf("Enter the total number of intervals: ");
    scanf("%d", &m);

    if (m == 1 || m <= 0 || m > N) {
        printf("Invalid input!!\n");
        return;
    }

    int input[m][2];

    printf("Enter the intervals (start and end for each):\n");
    for (int j = 0; j < m; j++) {
        if(scanf("%d %d", &input[j][0], &input[j][1]) != 2){
            printf("Invalid Interval inputs !\n");
            return;
        }
    }

    Merge(input, m);
}
