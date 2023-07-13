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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head->next==NULL){
            return(head) ;
        }
        
        stack<ListNode*> st1;
        ListNode* temp = head ;
        int count = 0 ;
        while(temp!=NULL){
            count += 1 ;
            temp = temp -> next ;
        }

        int remaining = count%k ;
        int last_index = count - remaining ;

        if (count<k){
            return(head) ;
        }

        ListNode* temp2 = (ListNode*)malloc(sizeof(struct ListNode)) ;

        temp = head ;
        head = temp2 ;
        count = 0 ;
        int flag = 0 ;
        int couti = 0 ;
        while(couti!=last_index){
            count += 1 ;
            st1.push(temp);
            if (count == k ){
                if (flag==0){
                    temp2->val = st1.top()->val ;
                    temp2->next = (ListNode*)malloc(sizeof(struct ListNode)) ;
                    st1.pop();
                    flag = 1 ;
                    count -= 1;
                    temp2 = temp2 ->next ;
                }

                while(count!=0){
                    temp2->val = st1.top()->val ;
                    temp2->next = (ListNode*)malloc(sizeof(struct ListNode)) ;
                    st1.pop() ;
                    count -= 1 ;
                    if (couti==last_index-1 && count==0){
                        cout << "ok" ;
                    }

                    else {
                        temp2 = temp2 ->next ;
                    }
                }
            }
            temp = temp -> next ;
            couti += 1 ;
            
        }
        temp2->next = temp ;

        return(head) ;
    }
};