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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp3 = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
        ListNode* head = temp3 ;

        if (l1==NULL){
            return(l2);
        }
        if (l2==NULL){
            return(l1);
        }

        int carry = 0 ; 
        int sum ;
        
        while (l1!=NULL && l2!=NULL){
            sum = l1->val + l2->val + carry ;
            carry = sum/10 ;
            sum = sum%10 ;
            
            
            cout << sum << "  "  ;
            temp3->val = sum ;
            temp3->next = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
            
            l1 = l1->next ;
            l2 = l2->next ;
            
            if (l1==NULL && l2==NULL){
                if (carry==0){
                    temp3->next = NULL ;
                }
                else {
                    temp3 = temp3->next ;
                    temp3->next = NULL ;
                    temp3->val = carry ;
                }
            }
            
            else{
                temp3 = temp3->next ;
            }
        }

        while (l1!=NULL){
            sum = l1->val + carry ;
            carry = sum/10 ;
            sum = sum%10 ;
            cout << sum << "  "  ;
            temp3->val = sum ;
            temp3->next = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
            l1 = l1->next ;
            if(l1==NULL){
                if (carry==0){
                    temp3->next = NULL ;
                }
                else {
                    temp3 = temp3->next ;
                    temp3->next = NULL ;
                    temp3->val = carry ;
                }
            }
        }

        
        while (l2!=NULL){
            sum = l2->val + carry ;
            carry = sum/10 ;
            sum = sum%10 ;
            cout << sum << "  "  ;
            temp3->val = sum ;
            temp3->next = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
            l2 = l2->next ;
            if(l2==NULL){
                if (carry==0){
                    temp3->next = NULL ;
                }
                else {
                    temp3 = temp3->next ;
                    temp3->next = NULL ;
                    temp3->val = carry ;
                }
            }
        }

        cout << endl << endl ;

        ListNode* temp4  = head ;
        while(temp4!=NULL){
            cout << temp4->val << " " ;
            temp4=temp4->next ;
        }
        return(head) ;
    }
};