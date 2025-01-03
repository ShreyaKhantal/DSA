#include<iostream>
using namespace std;
int size=5;
int q[5];
int f=-1,r=-1;
void enqueue(){
    if((f==0&&r==size-1)||((r+1)%size==f)) {
        cout<<"Queue is full"<<endl;
    }
    else if(f==-1){
        f=0;
        r=0;
        cout<<"Enter Data: ";
        cin>>q[r];
    }
    else if(r==size-1&&f!=0){
        r=0;
        cout<<"Enter Data: ";
        cin>>q[r];
    }
    else{
        cout<<"Enter Data: ";
        cin>>q[++r];
    }
}
void dequeue(){
    if(f==-1){
        cout<<"Empty queue"<<endl;
        return ;
    }
    cout<<"Deleted element is: "<<q[f]<<endl;
    if(f==r) {
        f=-1;
        r=-1;
    }
    else if(f==size-1) {
        f=0;
    }
    else
    {
        f++;
    }
}
void traversal()
{
    if(f==-1){
        cout<<"Empty queue"<<endl;
        return;
    }
    else if(r>=f) {
        cout<<"Queue: ";
        for(int i=f;i<=r;i++){
            cout<<q[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        for(int i=f;i<size;i++){
            cout<<q[i]<<" ";
        }
        for(int i=0;i<=r;i++){
            cout<<q[i]<<" ";
        }
    }
}
int main(){
    int ch;
    cout<<"1.Enqueue"<<endl;
    cout<<"2.Dequeue"<<endl;
    cout<<"3.Traversal"<<endl;
    cout<<"4.Exit"<<endl;
    do{
        cout<<"Enter Choice: ";
        cin>>ch;
        switch(ch){
            case 1: enqueue();break;
            case 2: dequeue();break;
            case 3: traversal(); break;
            case 4: break;
            default: cout<<"Wrong choice"<<endl;
        }
    } while (ch!=4);
}
