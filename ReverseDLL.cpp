//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>

/* a Node of the doubly linked list */
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        Node* before=NULL;
        Node *current=head;
        while (current!=NULL){
            before=current->prev;
            current->prev=current->next;
            current->next=before;
            current=current->prev;
        }
        return before? before->prev : head;
    }
};


