#include<bits/stdc++.h>

int n, dp[1000][1000];

void init(){
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            dp[i][j]= -1;
        }
    }
}

int countPS(string str,int i, int j){
    
    if (i > j)
        return 0;
 
    if (dp[i][j] != -1)
        return dp[i][j];
 
    if (i == j)
        return dp[i][j] = 1;
 
    else if (str[i] == str[j])
        return dp[i][j]
               = countPS(str,i + 1, j) + 
                countPS(str,i, j - 1) + 1;
 
    else
        return dp[i][j] = countPS(str,i + 1, j) +
                          countPS(str,i, j - 1) -
                          countPS(str,i + 1, j - 1);
}

int countPS(string str)
{
    init();
    int n= str.length();
    return countPS(str,0, n-1);
}
 