#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main()
{
    int n;
    cin>>n;
    
    vector<int> v;
    int sum=0;
    for(int i=0; i<n; i++){
        int curr;
        cin>>curr;
        v.push_back(curr);
        sum+=curr;
    }
    
    bool t[n+1][sum+1];
    
    for(int i=0; i<n+1; i++){
        t[i][0]=1;
    }
    
    for(int i=1; i<n+1; i++){
        t[0][i]=0;
    }
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(v[i-1] <= j){
                t[i][j]= t[i-1][j] || t[i-1][j-v[i-1]];
            }else{
                t[i][j]= t[i-1][j];
            }
        }
    }
    vector<int> sumvalues;
    for(int j=0; j<(sum+1)/2; j++){
        if(t[n][j]== 1){
            sumvalues.push_back(t[n][j]);
        }
        
    }
    int i;
    for( i=0; i<sumvalues.size(); i++){
        if(sum-2*sumvalues[i] <=0){
            break;
        }
    }
    cout<<i<<" "<<sum-i<<endl;
    
	return 0;
}