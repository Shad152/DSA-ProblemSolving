#include<bits/stdc++.h>
using namespace std;
const int N=(int)1e6+10;
int A[N],B[N];
int n,m,k;
int check(int mid){
    int i=0,j=m;
    int count=0;
    while(i<n){
        while(j-1 >= 0 && A[i]+B[j-1]>mid){
            j--;
        }
        count+=j;
        i++;
    }
    return count;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> B[i];
        }
        sort(A, A + n);
        sort(B, B + m);
        int lo = 0, hi = (int)2e4;
        int ans = A[0] + B[0];
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (check(mid) >= k)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << ans<<'\n';
    }
    
    
    
}