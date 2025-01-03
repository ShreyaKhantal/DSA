#include<iostream>
using namespace std;
int s=20;
int q[20];
int f=-1,r=-1;

void enqueue(){
    if(r<s){
      cout<<"Enter Data: ";
        if(f==-1){
            f=0;
            r=0;
            cin>>q[r];
        }else{
            cin>>q[++r];
        }
    }
    else
    {
        cout<<"Queue is full"<<endl;
    }
}

void dequeue()
{
    if(f==-1){
        cout<<"Queue is empty"<<endl;
    }
    else if(f==r){
        cout<<"Deleted element is: "<<q[f]<<endl;
        f=-1;
        r=-1;
    }
    else{
        cout<<"Deleted element is: "<<q[f]<<endl;
        f++;
    }
}
void traversal(){
    if(f==-1){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue: ";
        for(int i=f;i<=r;i++){
            cout<<q[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int ch;
    cout<<"1.Enqueue"<<endl;
    cout<<"2.Dequeue"<<endl;
    cout<<"3.Traversal"<<endl;
    cout<<"4.Exit"<<endl;
    do{
        cout<<"\nEnter Choice: ";
        cin>>ch;
        switch(ch){
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: traversal(); break;
            case 4: break;
            default: cout<<"Wrong choice entered"<<endl;
        }
    } while (ch!=4);
}
