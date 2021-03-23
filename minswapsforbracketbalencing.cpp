 int minimumNumberOfSwaps(string s){
        // int count=0;
        // int n=s.length();
        // vector<int> p;
        
        // for(int i=0; i<n; i++){
        //     if(s[i]=='['){
        //         p.push_back(i);
        //     }
        // }
        // int idx=0;
        // int ans=0;
        // for(int i=0; i<n; i++){
        //     if(s[i]=='['){
        //         idx++;
        //         count++;
        //     }else{
        //         count--;
        //         if(count<0){
        //             ans+= p[idx]-i;
        //             swap(s[i], s[p[idx]]);
        //             idx++;
        //             count=1;
        //         }
        //     }
        // }
        
        int open=0, close=0;
        int fault=0;
        int ans=0;
        int n=s.length();
        for(int i=0; i<n; i++){
            if(s[i]== ']'){
                close++;
                fault=close-open;
            }else{
                if(fault>0){
                    ans+= fault;
                    fault--;
                }
                open++;
                
            }
        }
        return ans;
        
    }