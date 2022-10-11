#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;


    // constructor
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    //DESTRUCTOR
    ~Node(){
        int val = this -> data;
        if(next != NULL){
            delete next;
            next =NULL;
        }
        cout<<"memory free for node with data "<<val <<endl;
    }
};
            /*********    TRAVERSAL    *********/
void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout <<temp ->data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
            /*********   GIVES LENGTH OF LINKED LIST   *********/
int getLength(Node* head){
    int len =0;
    Node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}
            /*********    INSERTION AT HEAD    *********/
void insertAthead(Node* &head, int d){
    Node* temp = new Node(d);
    temp ->next = head;
    head -> prev = temp;
    head = temp;
}
            /*********   INSERTION AT TAIL    *********/
void inserAttail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}
            /*********    INSERTIOM AT POSITION    *********/
void insertAtposition(Node* &tail, Node* &head, int position, int d){
    //insert at start
    if(position == 1){
        insertAthead(head, d);
        return;
    }

    Node* temp = head;
    int cnt =1;

    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }
    //insert at last position
    if(temp -> next == NULL){
        inserAttail(tail , d);
        return;
    }

    //creating a node for d
    Node* nodeToinsert = new Node(d);

    nodeToinsert -> next =  temp -> next;
    temp -> next -> prev = nodeToinsert;
    temp -> next = nodeToinsert;
    nodeToinsert -> prev = temp;
} 

           /******     DELETING NODE    *******/
void deletenode(int position, Node* &head)
{
    //deleting first or start node
    if(position == 1)
    {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node* curr =head;
        Node* prev =NULL;

        int cnt =1;
        while(cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        curr -> prev =NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}
int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    //cout<<getLength(head)<< endl;

    insertAthead(head, 11);
    print(head);
    insertAthead(head, 9);
    print(head);
    insertAthead(head,8);
    print(head);
    insertAthead(head, 7);
    print(head);

    inserAttail(tail ,25);
    print(head);

    insertAtposition(tail, head, 2, 100);
    print(head);
    insertAtposition(tail, head, 1, 101);
    print(head);
    insertAtposition(tail, head, 9, 102);
    print(head);

    deletenode(1, head);
    print(head);
    deletenode(5, head);
    print(head);

    return 0;
}