#include<iostream>
#include<string>
using namespace std;
int main(){
    long long n, x, bin, mx, sz, h, l, g;
    string a;
    char ans;
    bool inc[1000000];
    cin>>n;
    while(n--){
        cin>>a;
        sz = a.size();
        for(int i=0;i<sz-1;i++){
            inc[i]= a[i]>a[i+1];
        }
        cin>>x;
        mx =(sz*(sz+1))>>1;
        h = sz;
        //high is in
        l = 0;
        //low is out
        while(l+1<h){
            g = (l+h)>>1;
            bin = (g*(g+1))>>1;
            if (mx-bin<x) h=g;
            else l=g;
        }
        g = h;
        x -= mx - ((g*(g+1))>>1);
        g = sz - g;
        cout<<g<<' '<<x;
        for(int i=0; x;i++){
            if(g && inc[i]) g--;
            else x--;
            ans = a[i];
        }
        cout<<ans;
    }
    cout<<'\n';
}