#include<bits/stdc++.h>
using namespace std;

int arr[1000][1000];
int dp[1000][1000];

int mat[8][4] = {
    {0,0,0,0},
    {1,1,1,1},
    {0,0,1,1},
    {1,1,0,0},
    {0,1,1,0},
    {0,1,0,1},
    {1,0,0,1},
    {1,0,1,0}
};

bool isvalid(int r, int c, int n, int m){
    if(r<0 || r>=n || c<0 || c>=m || arr[r][c]==0){
        return false;
    }
    return true;
}

void dfs(int r, int c, int n, int m, int l){
    dp[r][c]= 1;
    if(l==0){
        return;
    }

    int type = arr[r][c];

    for(int i=0; i<4; i++){

        if(mat[type][i]){
            if(i==0){
                if(isvalid(r,c-1, n, m)){
                    int type = arr[r][c-1];
                    if(mat[type][1] && dp[r][c-1] ==0){
                        dfs(r, c-1, n, m,l-1);
                    }
                        
                }
            }
            if(i==1){
                if(isvalid(r, c+1, n, m)){
                    int type= arr[r][c+1];
                    if(mat[type][0] && dp[r][c+1] ==0){
                        dfs(r, c+1, n, m, l-1);
                    }
                }
            }
            if(i==2){
                if(isvalid(r-1, c, n, m)){
                    int type= arr[r-1][c];
                    if(mat[type][3] && dp[r-1][c]==0){
                        dfs(r-1, c, n, m, l-1);
                    }
                }
            }
            if(i==3){
                if(isvalid(r+1, c, n, m)){
                    int type = arr[r+1][c];
                    if(mat[type][2] && dp[r+1][c]==0){
                        dfs(r+1, c, n, m, l-1);
                    }
                }
            }
        }
        
    }
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int N,M,R,C,L;
        cin>>N>>M>>R>>C>>L;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                dp[i][j]=0;
                cin>>arr[i][j];
                
            }
        }
        
        if(arr[R][C]== 0){
            cout<<"0"<<endl;
        }else{
            dfs(R,C, N, M, L-1);
            

            int count=0;
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<M;j++)
                {
                    if(dp[i][j]==1)
                    count++;
                }
            }
            cout<<count<<endl;
        }
    }

    
}