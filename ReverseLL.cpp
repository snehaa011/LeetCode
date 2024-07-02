//Recursion
class Solution {   
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* newHead=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }
};

//Iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *after=head;
        ListNode *before=NULL;
        ListNode *temp;
        while (after!=NULL){
            temp=after->next;
            after->next=before;
            before=after;
            after=temp;
        }
        return before;
    }
};
