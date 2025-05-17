#include<bits/stdc++.h>
using namespace std;
const int N=(int)(2e5)+10;
set<int> adj[N];
vector<int> indeg;
vector<int> smallestPermutation;
set<int> taken;
void kahns(int n){
    priority_queue<int> que;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            que.push(-i);
        }
    }
    while(!que.empty()){
        int cur=-que.top();
        que.pop();
        if(taken.count(cur)) continue;
        smallestPermutation.push_back(cur);

        for(int child:adj[cur]){
            indeg[child]--;
            if(indeg[child]==0){
                que.push(-child);
            }
        }
        taken.insert(-cur);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    indeg.assign(n+1,0);
    for (int  i = 0; i < m; i++) {
        int a,b;
        cin>>a>>b;
        adj[a].insert(b);
        indeg[b]++;
    }
    kahns(n);
    int total=(int)smallestPermutation.size();
    if(total<n){
        cout<<"-1";
    }else{
        for(int val:smallestPermutation){
            cout<<val<<" ";
        }
    }
    
}