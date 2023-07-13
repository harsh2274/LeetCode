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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> unset ;
        if (head==NULL) {
            return(head) ;
        }
        while(head->next!=NULL){
            
            auto it = unset.find(head);  
            if ( it == unset.end() ) {   
                unset.insert(head) ;  
            }   
            else {
                return(head) ;
            }
            head = head->next ;
        }
        return(NULL) ;
    }
};