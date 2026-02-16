

#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int adjMat[n+1][m+1];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjMat[u][v]=w;
        adjMat[v][u]=w;
    }    

    
}