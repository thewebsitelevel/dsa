char expected(char a){
    return (a=='1')? '0': '1';
}


int minFlips (string s)
{   
    
    int n=s.length();
    int c1=0;
    int c2=0;
    int e='0';
    for(int i=0; i<n; i++){
        if(s[i] != e){
            c1++;
        }
        e=expected(e);
    }
    
    e='1';
    for(int i=0; i<n; i++){
        if(s[i] != e){
            c2++;
        }
        e=expected(e);
    }

    //cout<<c1<<c2<<endl;
    return min(c1,c2);
    
}