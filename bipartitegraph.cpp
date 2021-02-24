11 11
0 1
1 3
3 5
0 2
2 4
4 5
4 6
7 8
8 9
9 10
7 10


bool isBipartite(int v, vector<int>adj[]){
	    int color[v];
	    memset(color, -1, sizeof(color));
	    
	   
	    for(int k=0; k<v; k++){
	        if(color[k] == -1){
	            stack<int> ver;
	            ver.push(k);
	            
	            color[k]=1;
	            
	            while(ver.size() != 0){
	                int t = ver.top();
	                ver.pop();
	                for(int i=0; i< adj[t].size(); i++){
	                    int cv= adj[t][i];
	                    
	                    if(color[cv]== -1){
	                        color[cv]=!color[t];
	                        //cout<<color[cv]<<"  "<<color[t]<<"here"<<endl;
	                        ver.push(cv);
	                    }else{
	                        if(color[cv] == color[t]){
	                            return false;
	                        }
	                    }
	                }
	            }
	            
	            
	        }
	        //cout<<k<<"st complete"<<endl;
	    }
	    return true;
	 

	    
	    
	    
	    
	    
	    
	    
	}