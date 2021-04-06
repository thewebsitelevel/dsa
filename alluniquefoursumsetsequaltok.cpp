vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> ans;
        int n=arr.size();
        set<vector<int>> s;
        
        sort(arr.begin(), arr.end());
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                int x=j+1, y=n-1;
                while(x<y){
                    if(arr[i]+arr[j]+arr[x]+arr[y]== k){
                        s.insert({arr[i], arr[j], arr[x], arr[y]});
                        x++;
                        y--;
                    }else if(arr[i]+arr[j]+arr[x]+arr[y] < k){
                        x++;
                    }else{
                        y--;
                    }
                }
            }
        }
        for(auto it=s.begin(); it!= s.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }