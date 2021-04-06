static bool compare(int a, int b){
        int c=0,d=0;
    
        while(a !=0){
            c+=a&1;
            a= a>>1;
        }
        while(b!=0){
            d+=b&1;
            b=b>>1;
        }
        return c>d;
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr, arr+n, compare);
    }