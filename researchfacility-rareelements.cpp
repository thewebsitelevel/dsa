#include <bits/stdc++.h>
using namespace std;



int bfs(int ** roads, bool ** vis, int row, int col, int rareelements, int n, int m  ){
	queue<pair<pair<int, int>, int> > q;
    
    q.push({{row, col},0});
    int elecount=0;
    int maxdis=0;
    while(q.size() != 0){
        pair<pair<int, int>, int> f= q.front();
        q.pop();
        int row= f.first.first;
        int col = f.first.second;
        int dis= f.second;
        
        if(roads[row][col] == 2){
            elecount++;
            maxdis= max(dis,maxdis);
        }
        
        if( (row+1) <n && vis[row+1][col]== false && roads[row+1][col] != 0){
            vis[row+1][col]= true;
            q.push({{row+1, col}, dis+1});
        }
        if( (col+1) <m && vis[row][col+1]== false && roads[row][col+1] !=0){
            vis[row][col+1]= true;
            q.push({{row, col+1}, dis+1});
        }
        if( (row-1) >=0 && vis[row-1][col]== false && roads[row-1][col] != 0){
            vis[row-1][col]= true;
            q.push({{row-1, col},dis+1} );
        }
        if( (col-1) >=0 && vis[row][col-1]== false && roads[row][col-1] !=0){
            vis[row][col-1]= true;
            q.push({{row, col-1}, dis+1});
        }
        
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            roads[i][j]= false;
        }
    }
    if(elecount== rareelements){
        return maxdis;
    }else{
        return INT_MAX;
    }
    
}


int main()
{
    int n,m;
    cin>>n>>m;
    
    int ** roads= new int*[n];
    bool ** vis = new bool*[n];
    
    for(int i=0; i<n; i++){
        roads[i]= new int[m];
        vis[i]= new bool[m];
        for(int j=0; j<m; j++){
            cin>>roads[i][j];
            vis[i][j]= false;
        }
    }
    int q;
    cin>>q;
    int ans= INT_MAX;
    for(int i=0; i<q; i++){
        int x,y;
        cin>>x>>y;
        roads[x][y]= 2;
    }
    
    int locationX, locationY;
    int dis=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(roads[i][j] != 0){
                int a=bfs(roads,vis, i, j, q, n, m);
                if(a < ans){
                    ans= a;
                    locationX= i;
                    locationY= j;
                }
            }
        }
    }
    cout<<locationX<<" "<<locationY<<" "<<dis<<endl;
 
	return 0;
}
