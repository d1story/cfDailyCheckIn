//https://codeforces.com/problemset/problem/1886/E

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int dp[1777777];
int fm[1777777];
int tranges[27][2];
int task[27];
pair<int,int> prog[200007];

bool cpm(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>prog[i].first;
        prog[i].second=i+1;
    }
    sort(&prog[0],&prog[n],cpm);
    for(int i=0;i<m;i++)
        cin>>task[i];
    for(int i=1;i<=(1<<m);i++){
        dp[i]=7777777;
        fm[i]=0;
    }
    dp[0]=0;
    for(int i=0;i<(1<<m);i++){
        if(dp[i]>=n) continue;
        for(int j=0;j<m;j++){
            if(i&(1<<j)) continue;
            int amt = ceil((long double)task[j]/prog[dp[i]].first);
            if(dp[i|(1<<j)]>dp[i]+amt+1)
                dp[i|(1<<j)] = dp[i]+amt+1;
                fm[i|(1<<j)] = i;
        }
    }
    if(dp[(1<<m)-1]<=n){
        int mask = (1<<m)-1;
        while(mask){
            int from = log2(fm[mask]^mask);
            tranges[from][0] = dp[fm[mask]];
            tranges[from][1] = dp[mask] - 1;
            mask &= fm[mask];
        }
        for(int i=0;i<m;i++){
            cout<<tranges[i][1]-tranges[i][0]+1<<' ';
            for(int j=tranges[i][0];j<tranges[i][1];j++) cout<<prog[j].second<<' ';
        }
    }
    else cout<<"NO\n";
}