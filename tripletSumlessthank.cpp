long long countTriplets(long long arr[], int n, long long sum)
	{   int c=0;
	    sort(arr, arr+n);
	    for(int i=0; i<n-2; i++){
	        int x=i+1, y=n-1;
	        while(x<y){
	            int s= arr[i]+arr[x]+arr[y];
	            if(s<sum){
	                c+=(y-x);
	                x++;
	            }else if(s== sum){
	                y--;
	            }else{
	                y--;
	            }
	        }
	    }
	    return c;
	}