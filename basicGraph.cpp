#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	int e,v;
    cin>>e>>v;
    
    int **edge = new int*[v];
    for(int i=0; i<v; i++){
        edge[i]= new int[v];
        for(int j=0; j<v; j++){
            edge[i][j]=0;
        }
    }
    
    for(int i=0; i<e; i++){
        int a,b;
        cin>>a>>b;
        edge[a][b]= 1;
        edge[b][a]= 1;
    }
    
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            cout<<edge[i][j];
        }
        cout<<endl;
    }
    
    
    return 0;
}