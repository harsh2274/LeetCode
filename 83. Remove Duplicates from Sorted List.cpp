/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int temp = -999 ;
        if (head==NULL){
            return (head) ;
        }

        ListNode* temp2 = head ;
        ListNode* temp3  ;

        while( temp2->next!=NULL){
            if(temp!=temp2->val){
                temp=temp2->val;
            }
            else {
                temp3->next = temp2->next ;
                temp2 = temp3 ;
            }
            cout << temp2-> val << "  " ;
            temp3 = temp2 ;
            temp2 = temp2->next;
            if (temp2->next==NULL and temp3->val == temp2->val){
                temp3->next = NULL ;
            }
        }
        return(head);
    }
};