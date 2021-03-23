unordered_map<string, int> f;
        int l=0,sl=0;
        
        for(int i=0; i<n; i++){
            f[arr[i]]++;
            
        }
        
       
        for(auto it=f.begin(); it!= f.end(); it++){
            if(it->second >l){
                l= it->second;
            }
        }
        
        for(auto it=f.begin(); it!= f.end(); it++){
            if(it->second >sl && it->second < l){
                sl= it->second;
            }
        }
        
        if(sl==0){
            sl=l;
        }
        for(auto it=f.begin(); it!= f.end(); it++){
            if(it->second ==sl){
                return it->first;
            }
        }