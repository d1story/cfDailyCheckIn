//https://codeforces.com/problemset/problem/1886/A

/*
mod 3 -> 0,1,2
1,1,1  1,1,2  1,2,2
1,4,1, 1,4,2+3n, 1+3n,2,5
6,11
6,9,10,11
edgecases
<6? not possible
*/

#include<iostream>
using namespace std;
int main(){
    int x,n;
    cin>>x;
    while(x--){
        cin>>n;
        if(n<7||n==9){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        if(n%3==0){
            cout<<n-5<<' '<<4<<' '<<1<<'\n';
        }
        else if(n%3==1){
            cout<<n-5<<' '<<4<<' '<<1<<'\n';
            continue;
        }
        else{
            cout<<n-7<<' '<<2<<' '<<5<<'\n';
            continue;
        }
    }
}