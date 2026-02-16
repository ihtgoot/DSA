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

0  ---> {}
1  ---> {2,3}
2  ---> {1,4,5}
3  ---> {1,4}
4  ---> {3,2,5}
5  ---> {2,4}


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
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
}