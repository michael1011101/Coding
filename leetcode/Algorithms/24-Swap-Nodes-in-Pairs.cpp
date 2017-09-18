#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

/**
 * Title: 24. Swap Nodes in Pairs
 Given a linked list, swap every two adjacent nodes and return its head.
 
 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.
 
 Your algorithm should use only constant space. 
 You may not modify the values in the list, only nodes itself can be changed.
 
 */

/** solution
    notice the first two node
    then we need four flag nodes to swap each two adjacent nodes.
    (slow, one, two, fast)
    then slow->two->one->fast;
         slow = one;
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

/*************************** Submit Part *****************************/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode* one, *two;
        ListNode* fast, *slow;
        for(slow = NULL, fast = head; fast&&fast->next;){
            one = fast;
            two = fast->next;
            fast = fast->next->next;
            
            if(slow == NULL){
                one->next = fast;
                two->next = one;
                slow = two;
                head = slow;
            }
            else{
                one->next = fast;
                two->next = one;
                slow->next = two;
            }
            slow = one;
        }
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
    ListNode* link = create(x, 1);
    
    Solution solution;
    ListNode* head = solution.swapPairs(link);
    
    displayList(head);
    return 0;
}

