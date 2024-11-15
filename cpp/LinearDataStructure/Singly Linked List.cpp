#include <iostream>
using namespace std;

struct node{
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
        p->next=NULL;
    }else{
        p->next=head;
        head=p;
    }
}
void insert_at_end(){
    struct node *p = new struct node;
    cout<<"Enter Data : ";
    cin>>p->data;
    if(head==NULL){
        head=p;
        p->next=NULL;
    }else{
        struct node *t= head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=p;
        p->next=NULL;
    }
}
void del_in_begin(){
    if(head==NULL){
        cout<<"Deletion not Possible"<<endl;
    }
    else{
        cout<<"Deleted data element is "<<head->data<<endl;
        head=head->next;
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
void insert_in_btw(){
    struct node *p= new struct node;
    cout<<"Enter Data : ";
    cin>>p->data;
       
    int position, count=0;
    cout<<"Enter position : ";
    cin>>position;
   
    struct node *t = head;
    while(t->next!=NULL){
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
    while(t->next!=NULL){
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
        struct node *p=head;
        cout<<"Traversal: ";
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
