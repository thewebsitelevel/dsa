#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ll n,m;
	cin>>n>>m;
	ll arr[n];
	ll l=0,r=0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		r=max(r,arr[i]);
	}
	ll ans=INT_MAX;
	while(l<=r){
		ll mid= l+ (r-l)/2;
		ll wood=0;
		for(int i=0; i<n; i++){
			if(arr[i]>=mid ){
				wood= wood+ arr[i]-mid;
			}
		}
			
		if(wood <m){
			r=mid-1;
		}else{
            ans =mid;
			l=mid+1;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}