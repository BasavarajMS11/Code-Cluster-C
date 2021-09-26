#include<stdio.h>
#include<limits.h>
#define max 10
#define maxe 100
#define I 9999


void floyd(int G[max][max], int n);

int main(){
    int G[max][max];
    int n, i, j, s;
    int edge[3][maxe];

    printf("Input no. of vertices: ");
    scanf("%d",&n);

    printf("Enter Adjacency Matrix\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &G[i][j]);

            if(G[i][j]==0)
                G[i][j] = I;
        }
    }

    printf("\n Entered Adjacency Matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf(" %d", G[i][j]);
        }
        printf("\n");
    }

    floyd(G, n);

}

void floyd(int G[max][max], int n){
    int distance[max][max];

    int i, j,k;

    for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                distance[i][j]=G[i][j];


    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){

                if(distance[i][j]>distance[i][k]+distance[k][j])
                    distance[i][j]=distance[i][k]+distance[k][j];


            }
        }
    }
    printf("\nResulting cost matrix with all pair shortest paths is: \n");

    for(i=0;i<n;i++){
            for(j=0;j<n;j++){

                if(i==j){
                    printf(" 0");
                }
                else if(distance[i][j]==I)
                    printf(" I");
                else
                    printf(" %d",distance[i][j]);
            }

            printf("\n");
    }

}
