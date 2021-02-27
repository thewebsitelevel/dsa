#include <bits/stdc++.h> 
using namespace std; 
 
int findday(int y, int m, int d){
    int t[]= {0,3,2,5,0,3,5,1,4,6,2,4};
    y-=m<3;
    
    return (y + y/4 - y/100 + y/400 + t[m-1] + d)%7;
}

  
// Driver Code 
int main()  
{  
    int y,m,d;
    cin>>d>>m>>y;
    
    int day= findday(y, m, d);
    if(day== 0){
        cout<<"Sunday";
    }if(day== 1){
        cout<<"Monday";
    }if(day== 2){
        cout<<"Tuesday";
    }if(day== 3){
        cout<<"Wednesday";
    }if(day== 4){
        cout<<"Thursday";
    }if(day== 5){
        cout<<"Friday";
    }if(day== 6){
        cout<<"Saturday";
    }
    
}  