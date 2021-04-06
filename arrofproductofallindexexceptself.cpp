typedef long long int ll;

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
     vector<ll> op;

    if(n==1){
        op.emplace_back(1);
        return op;
    }
  ll l[n],r[n];
  l[0]=nums[0];
  for(int i=1; i<n; i++){
      l[i]= nums[i]*l[i-1];
  }
  r[n-1]=nums[n-1];
  for(int i=n-2; i>=0; i--){
      r[i]= nums[i]*r[i+1];
  }
 op.push_back(r[1]);
  for(int i=1; i<n-1; i++){
      op.push_back(l[i-1]*r[i+1]);
  }
  op.push_back(l[n-2]);
            
    return op;
}