 bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        
        for(int i=n; i>=0; i--){
            for(int j=m; j>=0; j--){
                if(i== n && j== m){
                    dp[i][j]=true;
                }else if(j== m){
                    if(p[i]=='*'){
                        dp[i][j]= dp[i+1][j];
                    }else{
                        dp[i][j]= false;
                    }
                }else if(i== n){
                    dp[i][j]= false;
                }else{
                    if(p[i]== '?'){
                        dp[i][j]= dp[i+1][j+1];
                    }else if(p[i]== '*'){
                        dp[i][j]= dp[i][j+1] || dp[i+1][j];
                    }else{
                        if(s[j]==p[i]){
                            dp[i][j]= dp[i+1][j+1];
                        }else{
                            dp[i][j]= false;
                        }
                    }
                }
            }
        }
        return dp[0][0];
    }