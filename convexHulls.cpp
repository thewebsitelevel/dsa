#include <bits/stdc++.h>
#include <iostream>
using namespace std;


struct point{
    int x;
    int y;
};

struct point p0;


int orientation(point p, point q, point r){
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
    if(val == 0){
        return 0;
    }
    return val >0 ? 1:2;
}

void convexhull(point * points, int n){
    
    int l=0;
    
    for(int i=1; i<n; i++){
        if(points[i].x < points[l].x){
            l=i;
        }
    }
    
    int p=l, q;
    point arr[n];
    int k=0;
    
    
    do{
        arr[k]= points[p];
    	k++;
        
        q= (p+1)%n;
        
        
        for(int i=0; i<n; i++){
            if(orientation(points[p], points[i], points[q]) ==2){
                q=i;
            }
        }
        
        p=q;
        
    }while(p!= l);
    
     for (int i = 0; i < k; i++) 
        cout << "(" << arr[i].x << ", "
              << arr[i].y << ")\n";
        
    
    
}


int main()
{
	point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, 
                      {3, 0}, {0, 0}, {3, 3}};
    
    int n= sizeof(points)/ sizeof(points[0]);
    
    convexhull(points, n);
    
	return 0;
}