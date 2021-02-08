
int  editd(string s, string t, int l, int m){
    if(l==0 || m==0){
        return 0;
    }
    
    if(s[l-1]== t[m-1]){
        return editd(s, t, l-1, m-1);
    }else{
        return 1+ min(
        				min(
            				editd(s, t, l, m-1),
            				editd(s, t, l-1, m)
        					
        					),
            			editd(s, t, l-1, m-1)
        			);
    }
}
