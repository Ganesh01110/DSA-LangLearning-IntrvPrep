#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;       
    }
};
void traversal(node* head){
    node* temp=head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}

void search(node* head, int key){
    node* temp=head;
    int pos=0;
    while(temp!= NULL){
        pos++;
        if(temp->data== key){
            cout<<"key: "<<key<<" found at: "<<pos<<endl;
            return;
        }
        temp= temp->next;
       
    }
    cout<<"key: "<<key<<" not found"<<endl;
}

void insertathead(node* &head, int val){
    node* n= new node(val);
    n->next=head;
    head=n;
}

void removefromhead(node* &head){
    if(head==NULL) return;

    node* todelete= head;
    head= head->next;
    delete todelete;
}

void insertattail(node* &head, int val){
    node* n= new node(val);
    if(head==NULL){
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;

}

void deletefromtail(node* &head){
    if(head==NULL) return;
    if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }

    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
}

int main(){
    node* head=NULL;

    insertathead(head , 1);
    insertathead(head , 2);
    insertathead(head , 3);

    // node* temp=head;
    // while(temp!=NULL){
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }
    traversal(head);

    search(head , 2);

    removefromhead(head);
    traversal(head);

    insertattail(head , 4);
    insertattail(head , 5);
    traversal(head);

    deletefromtail(head);
    traversal(head);
}