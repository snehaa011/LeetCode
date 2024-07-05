class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res={INT_MAX,INT_MIN};
        int index=0, firstci=-1, prevci=-1;
        ListNode* prev=NULL;
        while (head){
            if (head->next && prev){
                if (head->val>prev->val && head->val>head->next->val || head->val<prev->val && head->val<head->next->val){
                    if (firstci==-1){
                        firstci=index;
                        prevci=index;
                    }else{
                        res[0]=min(res[0], index-prevci);
                        res[1]=max(res[1], index-firstci);
                        prevci=index;
                    }
                }
            }
            index++;
            prev=head;
            head=head->next;
        }
        vector<int> def={-1,-1};
        return (res[0]==INT_MAX)? def: res;
    }
};

//T(n) = O(n)
//S(n) = O(1)
