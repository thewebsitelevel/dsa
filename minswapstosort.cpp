int minSwaps(vector<int>&nums){
	    int n= nums.size();
	   // vector<int> t;
	   // unordered_map<int, int> f;
	   // for(int i=0; i<n; i++){
	   //     t.emplace_back(nums[i]);
	   //     f[nums[i]]= i;
	   // }
	   // sort(t.begin(), t.end());
	    
	   // int c=0;
	   // for(int i=0; i<n; i++){
	   //     if(nums[i] != t[i]){
	   //         c++;
	   //         swap(nums[i], nums[f[t[i]]]);
	   //         int temp=f[nums[i]];
	   //         f[nums[i]]= f[t[i]];;
	   //         f[t[i]]= temp;
	   //         cout<<c<<endl;
	   //         i--;
	            
	   //     }
	   // }
	   // return c;
	   vector<pair<int, int>> temp(n);
	   for(int i=0; i<n; i++){
	       temp[i]= {nums[i],i};
	   }
	   sort(temp.begin(), temp.end());
	   int c=0;
	   for(int i=0; i<n; i++){
	       if(temp[i].second != i){
	           c++;
	           swap(temp[i], temp[temp[i].second]);
	           i--;
	       }
	   }
	   return c;
	}