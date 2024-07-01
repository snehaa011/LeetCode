/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

//Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
   // Your code here
   Node *temp=head;
   while (temp!=NULL){
       pos--;
       if (pos==-1){
           Node *newNode=new Node(data);
           if (temp->next!=NULL){
               temp->next->prev=newNode;
           }
           newNode->next=temp->next;
           newNode->prev=temp;
           temp->next=newNode;
           break;
       }
       temp=temp->next;
   }
}
