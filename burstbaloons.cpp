int store[1000][1000];
class Solution {
public:
    
    int ans(int *arr, int si, int ei, int** store){
        if(si+1 == ei){
            return 0;
        }
        if(store[si][ei] != -1){
            return store[si][ei];
        }
        
        int maxi=INT_MIN;
        
        for(int k=si+1; k<ei; k++){
            int fa = ans(arr, si, k, store);
            int sa = ans(arr, k, ei, store );
            int ta = arr[si]* arr[k] * arr[ei];
            int total = fa+sa+ta;
            maxi = max(total, maxi);
        }
        store[si][ei]= maxi;
        return maxi;        
        
    }
    
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int arr[n+2];
        arr[0]=1;
        for(int i=1; i<n+1 ;i++){
            arr[i]= nums[i-1];
        }
        arr[n+1] = 1;
        
        int ** store = new int*[n+2];
        
        for(int i=0; i<n+2; i++){
            store[i] = new int[n+2];
            for(int j=0; j<n+2; j++){
                store[i][j]=-1;
            }
        }
        
        return ans(arr, 0, n+1, store);
        
    }
};