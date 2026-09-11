//  You are given an undirected graph with N nodes (numbered 1 through N).  
// For each valid i, the i-th node has a weight Wi. Also, for each pair of nodes i and 
// j, there is an edge connecting nodes if j – i ≠ Wj - Wi.  
 
// Find the number of connected components in this graph. 
 
// Input Format: 
//  The first line of the input contains a single integer T denoting the number of 
// test  cases. The description of T test cases follows. 
//  The first line of each test case contains a single integer N. 
//  The line contains N space-separated integers W1, W2, ..., WN. 
 
// Output Format : 
 
// For each test case, print a single line containing one integer --- the number of 
// components in the graph.

#include<stdio.h>

void main(){
    int T;
    
    printf("Enter T:");
    scanf("%d",&T);

    while (T--)
    {
        int N;

        printf("Enter N:");
        scanf("%d",&N);

        int W[N];

        for(int i = 0 ; i < N; i++){
            scanf("%d",&W[i]);
        }

        int firstkey = 1 - W[0];
        int allsame = 1;

        for(int i = 1; i < N; i++){
            int key = (i + 1) - W[i];

            if(key != firstkey){
                allsame = 0;
                break;
            }

            if(allsame == 1){
                printf("Connected component : %d",N);
            }
            else{
                printf("Connected componet : %d", 1);
            }
            T--;
        }
    }
    
}