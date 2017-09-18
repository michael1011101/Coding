#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

/**
 * Title: 21. Merge Two Sorted Lists
 Merge two sorted linked lists and return it as a new list. 
 The new list should be made by splicing together the nodes of the first two lists.
 */

/** solution
    判断l1,l2指向的数字大小，小的结点放入新链表中
    当一个链表走到空的时候，将另一个直接放到新链表后
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

/*************************** Submit Part *****************************/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode* head=NULL;
        ListNode* cur=NULL;
        ListNode* node;
        
        while(l1&&l2){
            if(l1->val < l2->val){
                node = l1;
                l1 = l1->next;
            }
            else {
                node = l2;
                l2 = l2->next;
            }
            
            if(head==NULL){
                head = node;
                cur = node;
            }
            else{
                cur->next = node;
                cur = cur->next;
            }
        }
        
        if(l1==NULL) cur->next = l2;
        if(l2==NULL) cur->next = l1;
        return head;
    }
};
/*************************** Submit Part *****************************/

ListNode* create(int x, int step){
    ListNode* head=NULL;
    ListNode* cur=NULL;
    ListNode* node;
    
    for(int i=1; i<=x; i+=step){
        node = new ListNode(i);
        if(head == NULL){
            head = node;
            cur = node;
        }
        else{
            cur->next = node;
            cur = cur->next;
        }
    }
    return head;
}

ListNode* displayList(ListNode* head){
    ListNode* cur = head;
    while(cur != NULL){
        cout << cur->val;
        cur = cur->next;
        if(cur) cout << " -> ";
    }
    cout << endl;
    return head;
}

int main()
{
    int x;
    cin >> x;
    ListNode* l1 = create(x,1);
    ListNode* l2 = create(x,2);
    
    displayList(l1);
    displayList(l2);
    Solution solution;
    ListNode* head = solution.mergeTwoLists(l1, l2);
    
    displayList(head);
    return 0;
}

