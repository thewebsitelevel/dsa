bool dfs(vector<int> adj[], int v, bool *vis, bool *helper, int sv){
        
            vis[sv]=1;
            helper[sv]= 1;
            
            for(int i=0; i<adj[sv].size(); i++){
                if(helper[adj[sv][i]]== true) 
                    return true;
                if(vis[ adj[sv][i]  ]== 0){
                    bool ans = dfs(adj, v, vis, helper, adj[sv][i] );
                    if(ans== true){
                        return true;
                    }
                }
            }
            
        
        helper[sv]= false;
        return false;
    }

	bool isCyclic(int v, vector<int> adj[]) {
	   
	   bool * vis = new bool[v];
	   bool * helper = new bool[v];
	   
	   for(int j=0; j<v; j++){
            vis[j]=false;
            helper[j]= false;
        }
        
	   
	   
	   for(int i=0; i<v; i++){
	       if(vis[i]== 0){
	            bool ans =dfs(adj, v, vis, helper, i);
	            if(ans == true){
	                return true;
	            }
	            
	       }
	       
	   }
	   return false;
	}