int search(vector<int>& arr, int key) {
        int h= arr.size()-1;
        int l=0;
        int n= h;
        if(h==0){
            if(key== arr[0]){
                return 0;
            }else{
                return -1;
            }
        }
        if(h==1){
            if(key== arr[0]){
                return 0;
            }else if(key == arr[1]){
                return 1;
            }
        }
    int mid;
    while(l<= h){
        mid = l + (h-l)/2;
        
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;
        
        if(arr[mid] <= arr[next] && arr[mid]<= arr[prev]){
            break;
        }else if(arr[h] <= arr[mid]){
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    
    int ll=0;
    int lr=mid-1;
    int rl= mid;
    int rr=n;
    
    while(ll<= lr){
        int mid= ll + (lr-ll)/2;
        
        if(arr[mid]== key){
            return mid;
        }else if(arr[mid] > key){
            lr=mid-1;
        }else{
            ll= mid+1;
        }
    }
    
    while(rl <= rr){
        int mid = rl + (rr-rl)/2;
        
        if(arr[mid]== key){
            return mid;
        }else if(arr[mid] > key){
            rr=mid-1;
        }else{
            rl=mid+1;
        }
    }
    return -1;
    }