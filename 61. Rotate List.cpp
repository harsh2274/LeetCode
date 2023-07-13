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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head ;
        int count = 0 ;
        
        if(head==NULL || head->next==NULL){
            return(head);
        }

        while(temp!=NULL){
            count ++ ;
            temp = temp->next ; 
        }
        cout << count ;
        int num = k%count ;

        while(num>0){
            temp = head ;
            ListNode* temp2 ;
            while(temp->next!=NULL){
                temp2 = temp ;
                temp = temp->next ; 
            }
            temp->next = head ;
            head = temp ;
            temp2->next = NULL ;
            num-- ;  

        }

        return(head) ;
    }
};