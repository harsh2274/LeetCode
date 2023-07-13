/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode *> st1 ;
        stack<ListNode *> st2 ;
        while(headA!=NULL){
            st1.push(headA) ;
            headA = headA->next ;
        }
        while(headB!=NULL){
            st2.push(headB) ;
            headB = headB->next ;
        }
        ListNode* temp ;
        int flag = 0 ;
        while (!st1.empty() && !st2.empty() && st1.top()==st2.top()){
            temp = st1.top();
            st2.pop();
            st1.pop();
            flag = 1 ;
        }
        if (flag==0){
            return(NULL);
        }
        return(temp) ;

    }
};