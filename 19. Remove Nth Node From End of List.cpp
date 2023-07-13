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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head ;
        int count = 0 ;
        while(temp!=NULL){
            count += 1 ;
            temp=temp->next ;
        }

        temp = head ;
        int num = count - n ;
        int count2 = 0 ;
        cout << "nuum : " << num << endl ;

        if (num==0){
            if (head->next==NULL){
                return(NULL) ;
            }
            else {
                head = head->next ;
                return(head) ;
            }
        }

        while(temp!=NULL){
            if (num==count2+1){
                temp->next = temp->next->next ; 
            }
            count2 += 1 ;
            temp=temp->next ;
        }
        return(head) ;
    }
};