#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void solve(int ** mat, int isSafe, int row, int col,bool isBombUsed, int coins, int &ans){
    if(row<0 || col>=5 || col<0){
        ans= max(ans, coins);
        return;
    }
    if(isBombUsed){
        isSafe--;
    }
    
    if(mat[row][col]== 1 || mat[row][col]== 0){
        if(mat[row][col]== 1){
            coins++;
        }
        if(isBombUsed){
            isSafe--;
        }
        solve(mat, isSafe, row-1, col, isBombUsed, coins, ans);
        solve(mat, isSafe, row-1, col+1, isBombUsed, coins, ans);
        solve(mat, isSafe, row-1, col-1, isBombUsed, coins, ans);
    }else if(mat[row][col] == 2){
        if(isBombUsed && isSafe <=0){
            ans = max(ans,coins);
            return;
        }else if(isBombUsed && isSafe>0){
            isSafe--;
            solve(mat, isSafe, row-1, col, isBombUsed, coins, ans);
            solve(mat, isSafe, row-1, col+1, isBombUsed, coins, ans);
            solve(mat, isSafe, row-1, col-1, isBombUsed, coins, ans);
        }else{
            isBombUsed=true;
            isSafe=4;
            solve(mat, isSafe, row-1, col, isBombUsed, coins, ans);
            solve(mat, isSafe, row-1, col+1, isBombUsed, coins, ans);
            solve(mat, isSafe, row-1, col-1, isBombUsed, coins, ans);
        }
    }
}


int main(){
    int rows;
    cin>>rows;
    
    int ** mat = new int*[rows];
    
    for(int i=0; i<rows; i++){
        mat[i]= new int[5];
        for(int j=0; j<5; j++){
            cin>>mat[i][j];
        }
    }
    
    
    int ans=0;
    
    solve(mat, 0, rows-1, 1, false, 0, ans);
    solve(mat, 0, rows-1, 2, false, 0, ans);
    solve(mat, 0, rows-1, 3, false, 0, ans);
    cout<<ans;
    
}