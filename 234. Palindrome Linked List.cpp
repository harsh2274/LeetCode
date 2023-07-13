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
    bool isPalindrome(ListNode* head) {
        ListNode * st = head ;
        int count = 0 ;
        int stn_mid ; 
        while(st!=NULL){
            count += 1 ;
            st = st->next ; 
        }
        stn_mid = count/2 + count%2 ;
        int stn_mid1 = count/2 - count%2 ;
        st = head ;
        count = 0 ;
        stack<int> st1 ;
        while (st!=NULL){
            if (count>=stn_mid){
                st1.push(st->val);
            }
            st = st->next ; 
            count++ ;
        }
        while (head!=NULL && !st1.empty()){
            if (head->val != st1.top()){
                return(0);
            }
            st1.pop();
            head=head->next;
        }
        return(1);
    }
};