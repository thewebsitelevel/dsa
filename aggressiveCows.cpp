#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool isPossible(ll mid, ll *arr, ll cows, ll n){
   
    ll previ= arr[0];
    for(ll i=1; i<n; i++){
        if(arr[i]-previ >= mid  && cows> 0){
            previ=arr[i];
            cows--;
        }
        
    }
    if(cows ==0){
            return true;
        }
    
    return false;
}

void maxdis(ll l, ll r, ll *arr, ll cows, ll &ans, ll n){
    if(l>=r){
        return;
    }
    ll mid = l+(r-l)/2;
    if(isPossible(mid, arr, cows-1, n)){
        ans=mid;
        maxdis(mid+1, r, arr, cows, ans, n);
    }else{
        maxdis(l, mid, arr, cows, ans, n);
    }
    
}



void merge(ll *arr, ll mid, ll l, ll r){
    ll n1= mid-l+1;
    ll n2= r-mid;
    
    ll L[n1];
    ll R[n2];
    
    for(ll i=0; i<n1; i++){
        L[i]= arr[l+i];
    }
    for(ll j=0; j<n2; j++){
        R[j]= arr[mid+1+j];
    }
    
    ll i=0,j=0, k=l;
    
    while(i<n1 && j<n2){
        if(L[i] < R[j]){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]= R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]= R[j];
        j++;
        k++;
    }
}

void mergeSort(ll n, ll *arr, ll l , ll r){
    if(l>=r){
        return;
    }
    ll mid = (l+r)/2;
    mergeSort(n, arr, l, mid );
    mergeSort(n, arr, mid+1, r );
    merge(arr, mid, l, r);
}


int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,c;
	    cin>>n>>c;
	    ll *arr = new ll[n];
	    
	    for(ll i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    
	    mergeSort(n, arr, 0, n-1);
	    sort(arr, arr+n);
	    ll ans=0;
	    
	    maxdis(arr[0], arr[n-1], arr, c, ans, n);
	    
	    
	    cout<<ans<<endl;
	}
	
    return 0;
}