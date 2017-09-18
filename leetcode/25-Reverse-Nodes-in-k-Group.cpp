#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

/**
 * Title: 25. Reverse Nodes in k-Group
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 
 k is a positive integer and is less than or equal to the length of the linked list. 
 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 
 You may not alter the values in the nodes, only nodes itself may be changed.
 
 Only constant memory is allowed.
 
 For example,
 Given this linked list: 1->2->3->4->5
 
 For k = 2, you should return: 2->1->4->3->5
 
 For k = 3, you should return: 3->2->1->4->5
 */

/** solution
    reverse each k nodes as reversing list
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};


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

/*************************** Submit Part *****************************/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1)    return head;
        
        int num = 0;
        ListNode* cur=head;
        ListNode* fast=head;
        ListNode* slow=NULL;
        ListNode *pre, *ne=NULL;
        
        while(cur){
            cur = cur->next;
            num++;
        }

        while(num>=k){
            pre = fast;
            cur = fast->next;
            for(int i=1; i<k; ++i){
                ne = cur->next;
                cur->next = pre;
                pre = cur;
                cur = ne;
            }
            
            fast->next = ne;
            if(slow==NULL){
                head = pre;
                slow = pre;
            }
            else{
                slow->next = pre;
            }
            slow = fast;
            fast = ne;
            
            num -= k;
        }
        
        return head;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    cin >> x;
    ListNode* link = create(x, 1);
    
    Solution solution;
    int n;
    cin >> n;
    ListNode* head = solution.reverseKGroup(link, n);
    
    displayList(head);
    return 0;
}

