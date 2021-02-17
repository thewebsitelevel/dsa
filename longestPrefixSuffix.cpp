class Solution{
public:		

		
	int lps(string s)
	{
	    int lpsarr[s.length()];
	    
	    int i=1;
	    int j=0;
	    lpsarr[0]=0;
	    
	    while(i< s.length()){
	        if(s[i]== s[j]){
	            j++;
	            lpsarr[i]= j;
	            i++;
	            
	        }else{
	            if(j!=0){
	                j= lpsarr[j-1];
	                
	            }else{
	                lpsarr[i]=j;
	                i++;
	            }
	        }
	    }
	    int ans=0;
	    for( i=0; i<s.length(); i++){
	        cout<<lpsarr[i]<<" ";
	        
	    }
	    return lpsarr[s.length()-1];
	}
};