int *findTwoElement(int *arr, int n) {
        int *a = new int(2);
        sort(arr, arr+n);
        for(int i=1; i<n; i++){
            if((arr[i]^ arr[i-1])==0){
                a[0]=arr[i];
                break;
            }
            
        }
        int xor1=0;
        int xor2=1;
        for(int i=0; i<n; i++){
            xor1^=arr[i];
        }
        xor1^=a[0];
        
        for(int i=2; i<=n; i++){
            xor2^=i;
        }
        a[1]= xor1^xor2;
        
        return a;
    }