#include<bits/stdc++.h>
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool isValid(int r,int c,int N){
    if(r<0 || r>=N || c<0 || c>=N){
        return false;
    }
    return true;
}
pair<int,int> DFS(vector<string> &grid,vector<vector<int>> &vis,int r,int c){
  
    if(r<0 || r>=grid.size() || c<0 || c>=grid.size() || grid[r][c]=='.'){
        return {0,1};
    }
    else if(grid[r][c]=='#' && vis[r][c]!=0){
        return {0,0};
    }

    int area=1;
    int perimeter=0;
    vis[r][c] = 1;
    for(int k=0;k<4;k++){
        int x=r+dx[k];
        int y=c+dy[k];
        pair<int,int> areaAndPerimeter=DFS(grid,vis,x,y);
        area+=areaAndPerimeter.first;
        perimeter+=areaAndPerimeter.second;

    }
    return {area,perimeter};

}
int main(){
    int N;
    cin>>N;
    vector<string> grid(N);
    for (int  i = 0; i < N; i++){
        cin>>grid[i];
    }
    vector<vector<int>> vis(N,vector<int>(N,0));
    int maxArea=0;
    int minPerimeterWithMaxArea=4;
    int component=1;
    for(int r=0;r<N;r++){
        for(int c=0;c<N;c++){
            if(grid[r][c]=='#' && !vis[r][c]){
                pair<int,int> areaWithPerimeter=DFS(grid,vis,r,c);
                int curArea=areaWithPerimeter.first;
                int curPerimeter=areaWithPerimeter.second;
                if(curArea>maxArea){
                    maxArea=curArea;
                    minPerimeterWithMaxArea=curPerimeter;
                } else if(curArea==maxArea){
                    minPerimeterWithMaxArea=min(minPerimeterWithMaxArea,curPerimeter);
                }
            }
        }
    }
    cout<<maxArea<<" "<<minPerimeterWithMaxArea;
    return 0;
}
