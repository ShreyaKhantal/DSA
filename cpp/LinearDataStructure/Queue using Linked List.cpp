#include<iostream>
using namespace std;
struct node{
    int data;
    struct node*next;
} *f=NULL,*r=NULL;

void enqueue(){
    struct node*p=new struct node;
    cout<<"Enter data: ";
    cin>>p->data;
    p->next=NULL;
    if(f==NULL){
        f=p;
        r=p;
    }else{
        r->next=p;
        r=p;
    }
}

void dequeue(){
    if(f==NULL){
        cout<<"Empty Queue"<<endl;
    }
    else if(f->next==NULL){
        cout<<"Deleted element is: "<<f->data<<endl;
        f=NULL;
        r=NULL;
        cout<<endl;
    }else{
        cout<<"Deleted element is: "<<f->data<<endl;
        f=f->next;
        cout<<endl;
    }
}

void traversal(){
    if(f==NULL){
        cout<<"Empty queue"<<endl;
    }else{
        cout<<"Queue: ";
        struct node*t=f;
        while(t!=NULL){
            cout<<t->data<<" ";
            t=t->next;
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
            case 1: enqueue();break;
            case 2: dequeue();break;
            case 3: traversal(); break;
            case 4: break;
            default: cout<<"Wrong choice"<<endl;
        }
    } while (ch!=4);
}
