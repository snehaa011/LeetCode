class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *temp=head->next;
        ListNode *nexts=temp;
        while (nexts){
            int sum=0;
            while (nexts->val!=0){
                sum+=nexts->val;
                nexts=nexts->next;
            }
            temp->val=sum;
            temp->next=nexts->next;
            temp=temp->next;
            nexts=temp;
        }
        return head->next;
    }
};

//T(n) = O(n)
//S(n) = O(1)
