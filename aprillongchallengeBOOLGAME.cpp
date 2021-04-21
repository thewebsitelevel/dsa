#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int t;
	cin>>t;
	while(t--){
	    long long int n,m,k;
	    cin>>n>>m>>k;
	    vector<long long int> g(n+1);
	    for(long long int i=0; i<n; i++)
	        cin>>g[i+1];
	    vector<vector<pair<long long int, long long int>>> arr(n+1),dp(n+1);
	    for(long long int i=0; i<m; i++){
	        long long int u,v,d;
	        cin>>u>>v>>d;
	        arr[u].push_back(make_pair(i,d));
	        arr[v].push_back(make_pair(i,d));
	    }
	    dp[0].push_back(make_pair(0,0));
	    for(long long int i=1; i<=n; i++){
	        vector<pair<long long int, long long int>> temp;
	        temp.insert(temp.end(), dp[i-1].begin(), dp[i-1].end());
	        long long int curr=0, mask=0;
	        set<long long int> open;
	        for(long long int j=i; j>=1; j--){
	            curr+= g[j];
	            mask^=1LL<<j;
	            for(auto xyz:arr[j]){
	                if(open.count(xyz.first))
	                    curr+=xyz.second;
	                else
	                    open.insert(xyz.first);
	            }
	            if(j>1)
	                for(auto xyzj: dp[j-2])
	                    temp.push_back(make_pair(xyzj.first+curr, mask^xyzj.second));
	            else
	                temp.push_back(make_pair(curr,mask));
	        }
	        sort(temp.begin(), temp.end());
	        reverse(temp.begin(), temp.end());
	        set<long long int> sel;
	        long long int filled=0;
	        for(long long int j=0; j<temp.size() && filled<k; j++){
	            if(sel.count(temp[j].second))
	            continue;
	            dp[i].push_back(temp[j]);
	            filled++;
	            sel.insert(temp[j].second);
	        }
	    }
	    for(long long int i=0; i<k; i++)
	        cout<<dp[n][i].first<<" ";
	    cout<<endl;
	    
	}
	return 0;
}
