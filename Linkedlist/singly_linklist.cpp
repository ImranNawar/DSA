#include<iostream>
using namespace std;

class Node{

    public:
    int data;   //data of node
    Node* next; // pointer of node

// Constructor
    Node(int data)    
    { 
        this -> data = data;
        this -> next = NULL;
    }

// Destructor
~Node()
{
    int value = this -> data;
    // memory free
    if(this -> next != NULL)
    {
        delete next;
        this -> next =NULL;
    }
    cout<<"Memory is free for node with data "<< value <<endl;
}

};

            /*********    TRAVERSAL    *********/
void print(Node* &head)
{
    Node* temp=head;

    while(temp != NULL){
        cout<< temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

            /*******    INSERTION AT HEAD *******/
void InsertAtHead(Node* &head, int d){ //we take reference because we did not want to create copy, we want to change in original

    //new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;

}

            /*********   INSERTION AT TAIL ********/
void InsertAtTail(Node* &tail, int d)
{
    //new node create
    Node * temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

            /*********   INSERTION AT MIDDLE   ********/
void InsertAtPosition(Node* &tail, Node* &head, int position, int d)
{
    // insert at start
    if(position == 1){
        InsertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt =1; // in start we will be on first node

    while(cnt < position-1){      // traverse
        temp = temp -> next;
        cnt++;
    }
    // insert at laast position
    if(temp -> next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }

    //creating a node
    Node* nodetoinsert = new Node(d);

    nodetoinsert ->next = temp-> next;

    temp -> next = nodetoinsert;

}

            /******     DELETING NODE    *******/
void deletenode(int position, Node* &head)
{
    //deleting first or start node
    if(position == 1)
    {
        Node* temp = head;
        head = head -> next;
        //memory free start node
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
        prev -> next = curr -> next;
        curr-> next =NULL;
        delete curr;
    }
}

int main()
{
    //creqted a new node
    Node* node1 = new Node(10); // create a node / object of a class
    // cout << node1 -> data <<endl;
    // cout << node1 -> next <<endl;

    //had pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    InsertAtHead(head,12);
    print(head);

    InsertAtHead(head, 15);
    print(head);
    
    InsertAtTail(tail, 22);
    print(head);

    InsertAtPosition(tail, head, 3, 33);
    print(head);

    cout<<"head "<< head ->data<<endl;
    cout<<"tail "<< tail ->data<<endl;

    deletenode(1, head);
    print(head);
    deletenode(4, head);
    print(head);
    return 0;
}
