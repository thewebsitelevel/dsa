
 #include<bits/stdc++.h>
using namespace std;
void restroom(int n)
{
    queue<pair<int ,int > >q;
    vector<pair<int,int> >V;
    q.push({0,n-1});
    //q.push({-1,-1});
    while(!q.empty())
    {
        pair<int,int> P =q.front();
        q.pop();
        int low = P.first;
        int high = P.second;

            int mid = (low+high)/2;
            cout<<mid+1<<" ";
            if(high>=mid+1)
            q.push({mid+1,high});
            if(low<=(mid-1))
            q.push({low,mid-1});

    }
}
int main()
{
    int n;
    cin>>n;
    restroom(n);
}
