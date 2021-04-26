bool check(int mid, int n){
            int count=0;
            int f=5;
            while(f<=mid){
                count+= mid/f;
                f*=5;
            }
            return (count>=n);
        }
        
        int findNum(int n){
            
            if(n==1){
                return 5;
            }
            int low =0;
            int high = n*5;
            
            while(low<high){
                int mid= (low+high)/2;
                if(check(mid, n)){
                    high=mid;
                }else low =mid+1;
            }
            return low;
        }