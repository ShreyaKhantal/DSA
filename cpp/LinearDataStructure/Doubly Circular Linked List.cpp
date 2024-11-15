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
        cout<<"Enter choice : ";
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
        }
    }while(i!=9);
    return 0;
}

void insert_at_begin(){
    struct node *p = new struct node;
    cout<<"Enter Data : ";
    cin>>p->data;
    if(head==NULL){
        head=p;
        p->next=p;
        p->pre=p;
    }else{
        p->next=head;
        p->pre=head->pre;
        (head->pre)->next=p;
        head=p;
    }
}
void insert_at_end(){
    struct node *p = new struct node;
    cout<<"Enter Data : ";
    cin>>p->data;
    if(head==NULL){
        head=p;
        p->next=p;
        p->pre=p;
    }else{
        (head->pre)->next=p;
        p->pre=head->pre;
        p->next=head;
        head->pre=p;
    }
}

void del_in_begin(){
    if(head==NULL){
        cout<<"Deletion not Possible"<<endl;
    }
    else if(head == head->next){
        cout<<"Deleted data element is "<<head->data<<endl;
        head=NULL;
    }
    else{
        head=head->next;
        head->pre=(head->pre)->pre;
        (head->pre)->next=head;
    }
}

void del_at_end(){
    if (head==NULL){
        cout<<"Deletion not possible"<<endl;
    }
    else if(head->next==head){
        cout<<"Deleted element is "<<head->data<<endl;
        head=NULL;
    }
    else{
        cout<<"Deleted element is "<<(head->pre)->data<<endl;
        head->pre = (head->pre)->pre;
        (head->pre)->next = head;
    }
}

void insert_in_btw(){
    struct node *p= new struct node;
    cout<<"Enter Data : ";
    cin>>p->data;
        
    int position, count=0;
    cout<<"Enter position : ";
    cin>>position;
    
    struct node *t = head;
    while(t->next!=head){
        t=t->next;
        count++;
    }
    if(position <=count+2){
        t=head;
        while(position>2){
            position--;
            t=t->next;
        }
        p->next=t->next;
        p->pre=t;
        (t->next)->pre=p;
        t->next=p;
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
    while(t->next!=head){
        t=t->next;
        count++;
    }
    if(position <=count+1){
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
        while(p->next!=head){
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
    while(t->next!=head){
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

