int missingNumber(int arr[], int n) { 
    
    for(int i=0; i<n; i++){
        if(arr[i]>0 && arr[i] <=n){
            if(arr[i] != arr[arr[i]-1]){
               swap(arr[i], arr[arr[i]-1]);
               i--;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        if(arr[i] != i+1){
            return i+1;
        }
    }
    
    return n+1;
} 