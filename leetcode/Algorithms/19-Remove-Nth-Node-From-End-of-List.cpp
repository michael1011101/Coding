#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

/**
 * Title: 19. Remove Nth Node From End of List
 Given a linked list, remove the nth node from the end of list and return its head.
 
 For example,
 
 Given linked list: 1->2->3->4->5, and n = 2.
 
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Try to do this in one pass.
 */

/** solution
 1. head is NULL
    return NULL
 2. 设置快、慢指针
    快指针先走n步
    2.1 如果快指针已经指向链表结尾的NULL处，
        分情况：
            链表长度小于n， 直接返回head
            否则，首结点就是倒数第N个结点，返回head->next
    2.2 如果快指针没到链表尾，那么慢指针指向首结点，两个指针同时向后移动，
        直到快指针指向尾结点，那么慢指针指向倒数N+1个结点处
        删除慢结点的下一个结点
 
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

/*************************** Submit Part *****************************/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL)
            return NULL;
        
        int i;
        ListNode* fast, *slow;
        fast = head;
        for(i=0; i<n&&fast; ++i){
            fast = fast->next;
        }
        if(fast!=NULL){
            slow = head;
            while(fast->next){
                fast = fast->next;
                slow = slow->next;
            }
            
            ListNode *tmp = slow->next;
            slow->next = tmp->next;
            tmp->next = NULL;
        }
        else if(i==n){
            head = head->next;
        }
        return head;
    }
};
/*************************** Submit Part *****************************/

ListNode* create(int x){
    ListNode *head = NULL;
    ListNode *cur, *node;
    for(int i=1; i<=x; ++i){
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
    ListNode* head = create(x);
    
    int n;
    cin >> n;
    Solution solution;
    head = solution.removeNthFromEnd(head, n);
    
    displayList(head);
    return 0;
}

