/*
1 ----- 2
|       | \
|       |  5
|       | /
3 ----- 4 
  
12
13
24
34
35
45

        0   1   2   3   4   5

0   |   0   0   0   0   0   0   |
    |                           |
1   |   0   0   1   1   0   0   |
    |                           |
2   |   0   1   0   0   1   0   |
    |                           |
3   |   0   1   0   0   1   1   |
    |                           |
4   |   0   0   1   1   0   1   |
    |                           |
5   |   0   0   0   1   1   0   |
    


*/

#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int adjMat[n+1][m+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjMat[u][v]=1;
        adjMat[v][u]=1;
    }    

    
}