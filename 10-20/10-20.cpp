#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
        Node *prev;
        Node *next;
        char val;
        Node(Node *p, char a){
            prev = p;
            val = a;
            next = NULL;
        }
        Node(){
            prev=NULL;
            next=NULL;
            val='\0';
        }
        ~Node(){
            delete next;
        }
};
class LL{
    public:
        Node *head;
        Node *end;
        LL(){
            head=NULL;
            end = NULL;
        }
        ~LL(){
            delete head;
        }
        void remove(Node *tar){
            if(tar->prev == NULL) head=tar->next;
            else tar->prev->next = tar->next;
            if(tar->next == NULL) end = tar->prev;
            else tar->next->prev = tar->prev;
            tar->next=NULL;
            delete tar;
        }
        void addNode(char a){
            if(end == NULL) end = new Node(NULL,a);
            else {
                end->next = new Node(end,a);
                end = end->next;
            }
            if(head == NULL) head = end;
        }
        void reset(){
            delete head;
            head = NULL;
            end= NULL;
        }
};

int main(){
    long long n, x, bin, mx, sz, h, l, g;
    char a;
    cin>>n;
    LL ls;
    Node *pt;
    while(n--){
        sz=0;
        getchar();
        while((a = getchar())!='\n'){
            ls.addNode(a);
            sz++;
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
        pt = ls.head;
        while(g&&pt!=NULL){
            if(g && (pt->prev!=NULL && pt->val<pt->prev->val)){
                g--;
                ls.remove(pt->prev);
            }
            else pt = pt->next;
        }
        pt = ls.head;
        while(--x){
            pt = pt->next;
        }
        cout<<pt->val;
        ls.reset();
    }
    cout<<'\n';
}