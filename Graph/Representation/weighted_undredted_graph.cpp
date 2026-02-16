
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<pair<int,int>>adjList[n+1];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }
    
}