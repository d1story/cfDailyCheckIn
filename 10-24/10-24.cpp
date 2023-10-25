//https://codeforces.com/problemset/problem/1886/D

#include<iostream>
#include<algorithm>
using namespace std;
class node{
    public:
        long long val;
        int lrange;
        int rrange;
        node* left;
        node* right;

        node(int l,int r, int *arr){
            if(l==r){
                lrange = l;
                rrange = r;
                val = arr[l];
            }
            else{
                lrange = l;
                rrange = r;
                left = new node(l,(r+l)/2,arr);
                right = new node((r+l)/2+1,r,arr);
                val=left->val * right ->val;
                val %= 998244353;
            }
        }

        void update(int &here, int &ival){
            if(lrange == rrange && lrange == here){
                val = ival;
                return;
            }
            if(here<=(lrange+rrange)/2)
                left->update(here, ival);
            else right->update(here, ival);
            val = left->val * right->val;
            val %= 998244353;
        }
};



int main(){
    int x,n,y,z;
    cin>>x>>n;
    char a;
    int *arr = new int[x-1];
    for(int i=0;i<x-1;i++){
        cin>>a;
        if(a=='?'){
            arr[i] = i;
        }
        else arr[i] = 1;
    }
    node hd(0,x-2,arr);
    cout<<hd.val<<'\n';
    for(int i=0;i<n;i++){
        cin>>y>>a;
        y--;
        z = (a=='?'?y:1);
        hd.update(y,z);
        cout<<hd.val<<'\n';
    }
}