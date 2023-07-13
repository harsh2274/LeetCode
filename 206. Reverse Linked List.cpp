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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head ;
       
        if(head==NULL){
            return(head) ;
        }
        if ((head->next)==NULL){
            return(head) ;
        }
        
        ListNode* temp2 = head->next ;
        ListNode* temp3 = head ;
        
        head->next = NULL ;

        while(temp2!=NULL){
            temp = temp3 ;
            temp3 = temp2 ;
            temp2 = temp2->next ;
            temp3->next = temp ;
        }
        return(temp3) ;
    }
};