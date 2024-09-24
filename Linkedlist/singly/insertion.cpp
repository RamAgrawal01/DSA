#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    
    }

    ~Node(){
        //destructor
        cout<<"Node with value: "<<this->data<<"deleted"<<endl;
    }
};

//i want to insert a node wight at the head of linked list
void insertAtHead(Node* &head ,Node* &tail, int data){

    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    //step 1->cration of new node and assign data
    Node* newNode = new Node(data);
    //step 2 -> next of new node join to head of old node
    newNode->next = head;
    //step3->set head at new node
    head = newNode;
}



//insert at tail
void insertAtTail(Node* &head,Node* &tail , int data){

    
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //create a node 
    Node* newNode = new Node(data);
    //set next of tail in the new node
    tail->next = newNode;
    //set tail to newnode
    tail = newNode;
}

//find length
int findLength(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    cout<<"Length of ll: "<<len;
    return len;
}

//insert at position
void insertAtPosition(int position,Node* &head , Node* &tail , int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    //find the position

    if(position==0){
        insertAtHead(head,tail,data);
        return;
    }

    int len=findLength(head);
    if(position==len){
        insertAtTail(head , tail , data);
        return;
    }

    int i =1;
    Node* prev = head;
    while(i<position){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    //creation of new node
    Node* newNode = new Node(data);
    //join newNode to curr Node
    newNode->next = curr;
    //join newNode to prev Node
    prev->next = newNode;
}

void deleteNode(int position , Node* &head , Node* &tail){
    //check if empty ll
    if(head==NULL){
        return;
    }

    //if position is first
    if(position==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp; //call destructor
        return;
    }

    //if position is last
    int len = findLength(head);
    if(position==len){
        //find prev
        int i = 1;
        Node* prev = head;
        while(i<position-1){
            prev = prev->next;
            i++;
        }
        //step2
        prev->next = NULL;
        //step2
        Node* temp = tail;
        //step3
        tail = prev;
        //step5
        delete temp;
        return;
    }

    //deleting specified node
    int i = 1;
    Node* prev = head;
    while(i<position-1){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    //step 2
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;

}  


//printing the linked list
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,100);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,10);
    insertAtHead(head,tail,5);

    insertAtTail(head,tail,77);
    insertAtHead(head, tail , 1);
    insertAtTail(head,tail,98);
     

    print(head);
     cout<<endl;
    // cout<<"head: -> "<<head->data<<endl;
    //  cout<<"tail: -> "<<tail->data<<endl;

    // insertAtPosition(7,head,tail,101); //3 ke bad print kro
    // cout<<endl;
    // print(head);
    // cout<<endl;
    //  cout<<"head: -> "<<head->data<<endl;
    //  cout<<"tail: -> "<<tail->data<<endl;
    deleteNode(1,head,tail);
    print(head);
    cout<<endl;
    deleteNode(6,head,tail);
    print(head);
    deleteNode(2,head,tail);
    print(head);
    return 0;
}