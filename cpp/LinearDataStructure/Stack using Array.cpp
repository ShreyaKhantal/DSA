#include <iostream>
using namespace std;

const int s = 5; //s for size
int stack[s];
int tos=-1;

int is_emp();
int is_full();
void push();
void pop();
void traverse();

int main() {
    int a;

    cout<<"Enter 1 to push \n";
    cout<<"Enter 2 to pop \n";
    cout<<"Enter 3 to traverse \n";
    cout<<"Enter 4 to exit \n";
    do{
        cout<<"Enter choice : ";
        cin>>a;
        
        switch(a){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: traverse(); break;
            case 4: break;
            default: cout<<"Enter correct choice \n"; break;
        }
    }while(a!=4);
    
    return 0;
}

int is_emp(){
    if(tos==-1){
        return 1;
    }else{
        return 0;}
}


int is_full(){
    if(tos==s-1){
        return 1;
    }else{
        return 0;}
}

void push(){
    if(is_full()){
        cout<<"Stack overflow"<<endl;
    }
    else{
        cout<<"Enter data : ";
        cin>>stack[++tos];
    }
}

void pop(){
    if(is_emp()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Popped element is "<<stack[tos--]<<endl;
    }
}

void traverse(){
    if(is_emp()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack: ";
        for(int i=0;i<=tos;i++)
            cout<<stack[i]<<" ";
    }
    cout<<endl;
}
