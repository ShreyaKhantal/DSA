#include <iostream>
using namespace std;

struct node{
    struct node *pre;
    int data;
    struct node *next;
}*head=NULL;

void insert_at_begin();
void insert_at_end();
void insert_in_btw();
void del_in_begin();
void del_at_end();
void del_in_btw();
void indexing();
void traverse();

int main(){
    int i;
    cout<<"1-To insert at beginning"<<endl;
        cout<<"2-To insert at end"<<endl;
        cout<<"3-To insert in between"<<endl;
        cout<<"4-Deletion in beginning"<<endl;
        cout<<"5-Deletion at end"<<endl;
        cout<<"6-Deletion in between"<<endl;
        cout<<"7-Traversing"<<endl;
        cout<<"8-Indexing"<<endl;
        cout<<"9-exit code"<<endl;
    do{
        cout<<"\nEnter choice : ";
        cin>>i;
        switch(i){
            case 1: insert_at_begin(); break;
            case 2: insert_at_end(); break;
            case 3: insert_in_btw(); break;
            case 4: del_in_begin(); break;
            case 5: del_at_end(); break;
            case 6: del_in_btw(); break;
            case 7: traverse(); break;
            case 8: indexing(); break;
            case 9: break;
            default: cout<<"Enter valid choice :) "<<endl;
        }
    }while(i!=9);
    return 0;
}

void insert_at_begin(){
    struct node *p = new struct node;
    cout<<"Enter Data : ";
    cin>>p->data;
    p->pre=NULL;
    if(head==NULL){
        head=p;
        p->next=NULL;
    }else{
        p->next=head;
        head->pre=p;
        head=p;
    }
}
void insert_at_end(){
    struct node *p = new struct node;
    cout<<"Enter Data : ";
    cin>>p->data;
    
    p->next=NULL;
    if(head==NULL){
        head=p;
        p->pre=NULL;
    }else{
        struct node *t= head;
        while(t->next!=NULL){
            t=t->next;
        }
        p->pre=t;
        t->next=p;
    }
}
void del_in_begin(){
    if(head==NULL){
        cout<<"Deletion not Possible"<<endl;
    }
    else if( head->next==NULL){
        cout<<"Deleted element is "<<head->data<<endl;
        head=NULL;
    }
    else{
        cout<<"Deleted element is "<<head->data<<endl;
        head=head->next;
        head->pre=NULL;
    }
}
void del_at_end(){
    if (head==NULL){
        cout<<"Deletion not possible"<<endl;
    }
    else if(head->next==NULL){
        cout<<"Deleted element is "<<head->data<<endl;
        head=NULL;
    }
    else{
        struct node *t = head;
        while((t->next)->next!=NULL){
            t=t->next;
        }
        cout<<"Deleted element is "<<(t->next)->data<<endl;
        t->next=NULL;
    }
}
void insert_in_btw(){ // not working for insertion at end
    struct node *p= new struct node;
    cout<<"Enter Data : ";
    cin>>p->data;
        
    int position, count=0;
    cout<<"Enter position : ";
    cin>>position;
    
    struct node *t = head;
    while(t!=NULL){
        t=t->next;
        count++;
    }
    if(position <=count+1){
        t=head;
        while(position>2){
            position--;
            t=t->next;
        }
        (t->next)->pre=p;
        p->next=t->next;
        t->next=p;
        p->pre=t;
    }
    else{
        cout<<"Wrong position";
    }
}
void del_in_btw(){
    int position, count=0;
    cout<<"Enter position : ";
    cin>>position;
    
    struct node *t = head;
    while(t->next!=NULL){
        t=t->next;
        count++;
    }
    if(position <= count){
        t=head;
        while(position>2){
            position--;
            t=t->next;
        }
        cout<<"Deleted element is "<<(t->next)->data<<endl;
        ((t->next)->next)->pre=t;
        t->next=(t->next)->next;
    }
    else{
        cout<<"Wrong position";
    }
}
void traverse(){
    if (head==NULL){
        cout<<"Traversal not possible"<<endl;
    }else{
        cout<<"Traversal: ";
        struct node *p=head;
        while(p->next!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<p->data<<endl;
    }
}
void indexing(){
    int position, count=0;
    cout<<"Enter position : ";
    cin>>position;
    
    struct node *t = head;
    while(t->next!=NULL){
        t=t->next;
        count++;
    }
    if (head==NULL){
        cout<<"Empty linked list"<<endl;
    }
    else if(position <=count+1){
        t=head;
        while(position>1){
            position--;
            t=t->next;
        }
        cout<<"Data is : "<<t->data<<endl;
    }
    else{
        cout<<"Wrong position entered"<<endl;
    }
}

