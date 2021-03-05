int maximumPath(int n, vector<vector<int>> arr)
    {
        int dp[n+1][n+1];
        for(int j=0; j<n; j++){
            dp[0][j]= arr[0][j];
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                if(j==0){
                    dp[i][j]= arr[i][j] + max(dp[i-1][j], dp[i-1][j+1]);
                }else if(j== n-1){
                    dp[i][j]= arr[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
                }else{
                    int t= max(dp[i-1][j-1], dp[i-1][j]);
                    dp[i][j]= arr[i][j] +max(t, dp[i-1][j+1]);
                }
            }
        }
        int maxi=dp[n-1][0];
        for(int i=0; i<n; i++){
            maxi= max(maxi, dp[n-1][i]);
        }
        return maxi;
    }