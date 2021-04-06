#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int x;
	    cin>>x;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    int l=0, r=1;
	    sort(arr, arr+n);
	    int ans=-1;
	    while(l<n && r<n){
	        if(abs(arr[l]-arr[r])==x){
	            ans=1;
	            break;
	        }else if(abs(arr[l]-arr[r])<x){
	            r++;
	        }else{
	            l++;
	        }
	    }
	    
	        cout<<ans<<endl;
	    
	}
	return 0;
}