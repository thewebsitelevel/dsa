#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int solve(int i, int j, string s, string arr[], int ssize, int ipsize, int id){
    
    int found=0;
    char temp;
    
    if(i>=0 && i<ipsize && j>=0 && j<ipsize && arr[i][j]== s[id]){
        temp= s[id];
        id+=1;
        arr[i][j]=0;     
      if(id == ssize){
          found =1;
      }else{
            found += solve(i+1, j, s,arr, ssize, ipsize, id);
          	found += solve(i, j+1, s,arr, ssize, ipsize, id);
          	found += solve(i, j-1, s,arr, ssize, ipsize, id);
         	found += solve(i-1, j, s,arr, ssize, ipsize, id);
        }
    }
    
    return found;    
}

int main()
{
	string s;
    cin>>s;
    string ip[]={ 		
                    "BBABBM",  
                    "CBMBBA",  
                    "IBABBG",  
                    "GOZBBI",  
                    "ABBBBC",  
                    "MCIGAM" 
                 };    
    
   	int ssize = s.length();
    
   	int ipsize = 6;  
    int ans= 0;
    for(int i=0; i<ipsize; i++){
        for(int j=0; j<ipsize; j++){
                ans+= solve(i, j, s, ip, ssize, ipsize, 0);
            
        }
    }
    
    cout<<ans;
    
	return 0;
}