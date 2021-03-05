#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int dp[101][101];
int arr[101][101];

bool issafe(int x, int y, int n, int m){
    return (x>=0 && y>=0 && x<n && y<m) ? 1:0;
}

void dfs(int x, int y, int n, int m, int cost){
    if(dp[x][y] > cost){
        dp[x][y]= cost;
        
        if(issafe(x+1, y, n, m) && arr[x+1][y]== 1){
            dfs(x+1, y, n, m, cost+1);
        }
        if(issafe(x-1, y, n, m) && arr[x-1][y]== 1){
            dfs(x-1, y, n, m, cost+1);
        }
        if(issafe(x, y+1, n, m) && arr[x][y+1] == 1){
            dfs(x, y+1, n, m, cost);
        }
        if(issafe(x, y-1, n, m) && arr[x][y-1]== 1){
            dfs(x, y-1, n, m, cost);
        }
        
    }
}


int main()
{
	int homex, homey, n, m, cost, destx, desty;
    
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            dp[i][j]= INT_MAX;
        }
    }
    cin>>homex>>homey;
    cin>>destx>>desty;
    
    dfs(homex, homey, n, m, 0);
    
    cout<<dp[destx][desty]<<endl;
    
	return 0;
}