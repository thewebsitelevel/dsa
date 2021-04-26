class Solution {
public:
    
    static bool compare(vector<int> a, vector<int> b){
        return a[1]< b[1];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> ip;
        int n=profit.size();
        
        for(int i=0; i<n; i++){
            ip.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(ip.begin(), ip.end(), compare);
        int dp[n];
        
        dp[0]=ip[0][2];
        
        for(int i=1; i<n; i++){
            int inc = ip[i][2];
            int low=0;
            int last=-1;
            int high= i-1;
            while(low<=high){
                int mid = (low+high)/2;
                
                if(ip[mid][1] <= ip[i][0]){
                    last=mid;
                    low= mid+1;
                }else high= mid-1;
            }
            if(last != -1) inc += dp[last];
            
            dp[i] = max(inc, dp[i-1]);
        }
        return dp[n-1];
    }
};