 bool isValid(int *arr, int n , int k, int mid){
        int s=1;
        int sum=0;
        
        
        for(int i=0; i<n; i++){
            
            if(arr[i] > mid) return 0;
            
            
            if(sum+ arr[i]> mid){
                s++;
                sum=arr[i];
                if(s>k){
                    return 0;
                }
            }else{
                sum+= arr[i];
            }
            
        }
        return true;
    }
    
    int findPages(int arr[], int n, int k) {
        // sort(arr, arr+n);
        // if(n <k) return -1;
        int sum=0;
        int m=0;
        for(int i=0; i<n; i++){
            sum+= arr[i];
            m=max(m, arr[i]);
        }
        
        int l=m;
        int r=sum;
        int ans=INT_MAX;
        while(l<= r){
            int mid= l + (r-l)/2;
            
            if(isValid(arr, n,k, mid)){
                ans=min(mid,ans);
                r=mid-1;
            }else{
                l= mid+1;
            }
            
            
        }
        
        return ans;
        
    }