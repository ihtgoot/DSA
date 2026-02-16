/*
1-----> 2
|       | \
|       |  5
V       V /
3-----> 4 
  


*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int>adjList[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
    }
    
}