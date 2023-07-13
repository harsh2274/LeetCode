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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* temp3 = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
        ListNode* head = temp3 ;

        if (list1==NULL){
            return(list2);
        }
        if (list2==NULL){
            return(list1);
        }

        while (list1!=NULL && list2!=NULL){
            cout << list1->val << "  " << list2->val << endl ;

            if (list1->val < list2->val){
                temp3->val = list1->val ;
                temp3->next = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
                //temp3 = temp3->next ;
                list1 = list1->next ;
            }
            else if(list1->val > list2->val){
                temp3->val = list2->val ;
                temp3->next = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
                //temp3 = temp3->next ;
                list2 = list2->next ;
            }
            else{
                temp3->val = list2->val ;
                temp3->next = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
                temp3 = temp3->next ;
                temp3->val = list1->val ;
                temp3->next = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
                list2 = list2->next ;
                list1 = list1->next ;
            }
            if (list1==NULL && list2==NULL){
                temp3->next = NULL ;
            }
            else{
                temp3 = temp3->next ;
            }
        }    
        while (list1!=NULL){
            temp3->val = list1->val ;
            temp3->next = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
            list1 = list1->next ;
            if (list1==NULL){
                 temp3->next=NULL ;
            }
            else {
                 temp3 = temp3->next ;
            }
        }  
        while (list2!=NULL){
            temp3->val = list2->val ;
            temp3->next = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
            list2 = list2->next ;
            if (list2==NULL){
                 temp3->next=NULL ;
            }
            else {
                 temp3 = temp3->next ;
            }
        }  
        temp3 = NULL ;
        return(head) ;
    }
};