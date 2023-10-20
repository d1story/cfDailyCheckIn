//https://codeforces.com/problemset/problem/1886/B


#include<iostream>
#include <iomanip>
#include<algorithm>
using namespace std;
long double dis(int a1, int a2, int b1, int b2){
    return sqrt((b1-a1)*(b1-a1)+(b2-a2)*(b2-a2));
}
int main(){
    int x,a1,a2,b1,b2,c1,c2;
    cout << setprecision(7);
    cin>>x;
    while(x--){
        cin>>a1>>a2>>b1>>b2>>c1>>c2;
        long double ans=1e10;
        //see if b covers both
        long double bo = dis(b1,b2,0,0);
        long double bh = dis(b1,b2,a1,a2);
        long double d = max(bo,bh);
        ans = min(ans, d);
        //see if c covers
        long double co = dis(c1,c2,0,0);
        long double ch = dis(c1,c2,a1,a2);
        d = max(co,ch);
        ans = min(ans, d);
        //see if both is shorter
        long double bc = dis(b1,b2,c1,c2);
        d = max(max(co,bh),bc/2);
        ans = min(ans, d);
        d = max(max(bo,ch),bc/2);
        ans = min(ans, d);
        cout<<ans<<'\n';
    }
}