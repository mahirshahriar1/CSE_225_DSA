#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);


struct node{
       int data;
       struct node *link;
};
//insert at end
struct node* add_at_end(struct node *ptr,int data){     
       struct node *temp=(struct node*)malloc(sizeof(struct node));
       temp->data=data;
       temp->link=NULL;
       ptr->link=temp;
       return temp;
}
//print linked list
void print_linkedlist(struct node* head){
       while(head!=NULL){
              cout<<head->data<<endl;
              head=head->link;
       }
       cout<<endl;
}
// add at beginning
struct node* add_beg(struct node *head,int data){
       struct node *ptr=(struct node*) malloc(sizeof(struct node));
       ptr->data=data;
       ptr->link=head;
       head=ptr;
       return head;
}
// add at beginning
void add_begv(struct node **head,int dat){
       struct node *ptr=(struct node*) malloc(sizeof(struct node));
       ptr->data=dat;
       ptr->link=*head;
       *head=ptr;
}

// add at a specified position
void add_at_pos(struct node *head,int data,int pos){
       struct node *ptr=head;
       struct node *ptr2=(struct node*) malloc(sizeof(struct node));
       ptr2->data=data;
       ptr2->link=NULL;
       
       pos--;
       while(pos!=1){
              ptr=ptr->link;
              pos--;
       }
       ptr2->link=ptr->link;
       ptr->link=ptr2;
}

// insert in a sorted linked list
void insert_sorted_list(struct node **head, int key){
       struct node* temp;
       struct node* neww=(struct node*) malloc(sizeof(struct node));
       neww->data=key;
       neww->link=NULL;      
  

       if(head==NULL||key<(*head)->data){
              neww->link=*head;
              *head=neww;
       }else{
              temp=*head;
              while(temp->link != NULL && (temp->link)->data < key){
                     temp=temp->link;
              }
              neww->link=temp->link;
              temp->link=neww;
       }
}


int main(){
    fastio
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
   
    struct node *head=(struct node*) malloc(sizeof(struct node));
    head->data=5;
    head->link=NULL;

    struct node *ptr=head;
    ptr=add_at_end(ptr,10);
    ptr=add_at_end(ptr,15);
    ptr=add_at_end(ptr,20);
  
    print_linkedlist(head);
//     head=add_beg(head,5);
//     add_begv(&head,3);
    

//     print_linkedlist(head);
//     add_at_pos(head,9,4);

//     print_linkedlist(head);

insert_sorted_list(&head,25);
print_linkedlist(head);

}
