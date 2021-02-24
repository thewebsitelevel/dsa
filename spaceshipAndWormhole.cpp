#include <bits/stdc++.h>
#include <iostream>
using namespace std;

  int ans=INT_MAX;
struct vertex{
    int x;
    int y;
};

int distance(struct vertex a, struct vertex b){
    return ( abs(b.x-a.x) + abs(b.y-a.y) );
}

void dfs(int** graph, int curr,int fin, bool *vis, int currdist ){
    if(curr== fin){
        ans= min(ans, currdist);
        return;
    }
   
    if(vis[curr]){
        return;
    }
    vis[curr]= true;
    for(int i=0; i<=fin; i++){
        
        dfs(graph, i, fin, vis, currdist + graph[curr][i]);
    }
    vis[curr]=0;
}

int main()
{
    struct vertex s;
    cin>>s.x;
    cin>>s.y;
    
    struct vertex d;
    cin>>d.x;
    cin>>d.y;
    
    int wormholes;
    cin>>wormholes;
    int gsize = (wormholes*2)+2;
    struct vertex *vertices = new struct vertex[gsize];
    int ** graph= new int*[gsize];
    
    for(int i=0; i<gsize; i++){
        graph[i]= new int[gsize];
        for(int j=0; j<gsize; j++){
            graph[i][j]=-1;
        }
    }
    vertices[0]= s;
    
    int tracker=1;
    int graphIndex=1;
    for(int i=0; i<wormholes; i++){
        struct vertex holestart;
        cin>>holestart.x;
        cin>>holestart.y;
        
        struct vertex holeend;
        cin>>holeend.x;
        cin>>holeend.y;
        
        int dist;
        cin>>dist;
        
        vertices[tracker]= holestart;
        tracker++;
        vertices[tracker]= holeend;
        tracker++;
        
        graph[graphIndex][graphIndex+1]= graph[graphIndex+1][graphIndex]= dist;
        graphIndex+=2;
    } 
    vertices[tracker]= d;
    
    for(int j=0; j<gsize; j++){
        graph[0][j]= distance(vertices[0], vertices[j]);
       	graph[gsize-1][j]= distance(vertices[gsize-1], vertices[j]);
    }
    
    
    for(int i=1; i<gsize; i++){
        for(int j=0; j<gsize; j++){
            if(i==j){
                graph[i][j]=0;
            }else if(graph[i][j]== -1){
                if(i%2 ==1){
                    graph[i][j]= graph[i][i+1] + distance(vertices[i+1], vertices[j]);
                }else{
                    graph[i][j]= graph[i][i-1] + distance(vertices[i-1], vertices[j]);
                }
            }
        }
    }
    
  
    int currans=0;
    bool *vis = new bool[gsize];
    memset(vis, 0, sizeof(vis));
   
    dfs(graph, 0, gsize-1 , vis, 0);
  
    
    cout<<ans;
	 
    
	return 0;
}