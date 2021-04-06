 ll findSubarray(vector<ll> arr, int n ) {
        unordered_map<int, int> f;
        
        ll c=0;
        ll prefixsum =0;
        f[prefixsum]=c;
        for(int i=-1; i<n; i++){
            prefixsum+= arr[i];
            
            if(f.find(prefixsum) != f.end()){
                c+=f[prefixsum];
                f[prefixsum]++;
            }else{
                f[prefixsum]++;
            }
        }
        return c;
    }