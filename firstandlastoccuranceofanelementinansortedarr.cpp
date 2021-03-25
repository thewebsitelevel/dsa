vector<int> find(int arr[], int n , int x )
{
    int l=0; int r=n-1;
    
    while(l<=r){
        int mid = l+ (r-l)/2;
        
        
        if(arr[mid]== x){
            l=mid;
            r=mid;
            break;
        }
        
        if(x> arr[mid]){
            l=mid+1; 
        }else{
            r=mid-1;
        }
    }
    vector<int> ans;
    if(arr[l] != x){
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    
    while(arr[l]==x){
        l--;
    }
    while(arr[r]==x){
        r++;
    }
    
    ans.emplace_back(l+1);
    ans.emplace_back(r-1);
    return ans;
}