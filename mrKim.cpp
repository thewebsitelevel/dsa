#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct point{
    int x,y;
}office, customer[102], home;
bool vis[102]= {false};
int mincost=INT_MAX;

int abs(int x){
    return x<0 ? x*-1:x;
}

int dis(point a, point b){
    return abs(a.x-b.x)+ abs(a.y-b.y);
}

void solve(int count, point parent, int i, int n, int cost){
    if(count ==n ){
        int temp = dis(parent, home);
        cost+= temp;
        if(mincost> cost){
            mincost=cost;
        }
        return;
    }
    vis[i]= true;
    for(int j=0; j<n; j++){
        if(!vis[j]){
            int temp = dis(parent, customer[j]);
            solve(count+1, customer[j], j, n, cost+temp);
        }
    }
    vis[i]= false;
}


int main()
{
    cin>>office.x>>office.y;
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>customer[i].x>>customer[i].y;
    }
    cin>>home.x>>home.y;
    int cost= 0;
    solve(0, office, n+1, n, cost);
    cout<<mincost<<endl;
	
	return 0;
}