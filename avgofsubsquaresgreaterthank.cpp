#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        
        double arr[n+1][m+1];
        
        for(ll i=0; i<=n; i++){
            for(ll j=0; j<=m; j++){
                if(i==0 || j==0) arr[i][j]=0;
                else cin>>arr[i][j];
            }
        }
        
        for(ll i=0; i<=n; i++){
            double prev=0;
            for(ll j=0; j<=m; j++){
                arr[i][j]+=prev;
                prev=arr[i][j];
            }
        }
        
        for(ll i=0; i<=m; i++){
            double prev=0;
            for(ll j=0; j<=n; j++){
                arr[j][i]+=prev;
                prev=arr[j][i];
                
            }
        }
        
        ll c=0;
        ll cmin= min(n,m);
        
        for(ll u=1; u<=cmin; u++){
            ll div= u*u;
            for( ll i=u; i<=n; i++){
                for(ll j=u; j<=m ; j++){
                    if((arr[i][j] + arr[i-u][j-u]- arr[i-u][j]- arr[i][j-u])/(div) >=k) c++;
                }
            }
        }
        
        cout<<c<<endl;
        
    }
	return 0;
}