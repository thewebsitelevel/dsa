#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print(int **mat, int v, int e, int sv, bool* vis){
    cout<<sv<<" ";
    vis[sv]= true;
    for(int i=0; i<v; i++){
        if(sv == i){
            continue;
        }
    	if(mat[sv][i] == 1){
            if(vis[i]== true){
                continue;
            }
            print(mat, v, e, i, vis);
        }    
    }
}

int main()
{
    int e,v;
    cin>>e>>v;
    
    int **mat = new int*[v];
    
    for(int i=0 ;i<v; i++){
        mat[i]= new int[v];
        for(int j=0; j<v; j++){
            mat[i][j]=0;
        }
    }
    bool *vis= new bool[v];
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<e; i++){
        int a,b;
        cin>>a>>b;
        mat[a][b]=1;
        mat[b][a]=1;
    }
    
    print(mat, v, e, 0, vis);
	
	return 0;
}