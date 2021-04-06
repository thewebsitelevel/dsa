int majorityElement(int a[], int size)
{   int count=1;
    int m=a[0];
    for(int i=1; i<size; i++){
        if(a[i]== m){
            count++;
        }else{
            count--;
            if(count ==0){
                m=a[i];
                count++;
            }
        }
    }
    int fcount=0;
    for(int i=0; i<size; i++){
        if(a[i]== m) fcount++;
    }
    if(fcount> size/2){
        return m;
    }
    return -1;
}