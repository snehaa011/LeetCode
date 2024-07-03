class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while (slow && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *temp, *before=NULL;
        while (slow){
            temp=slow->next;
            slow->next=before;
            before=slow;
            slow=temp;
        }
        int ms=0;
        ListNode* start=head;
        while (start && before){
            int sum=start->val + before->val;
            ms=max(sum,ms);
            start=start->next;
            before=before->next;
        }
        return ms;
    }
};

//T(n) = O(n)
//S(n) = O(1)
