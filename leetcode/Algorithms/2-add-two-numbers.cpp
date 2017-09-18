#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Title: 2. Add Two Numbers
    You are given two non-empty linked lists representing two non-negative integers.
    The digits are stored in reverse order and each of their nodes contain a single digit.
    Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
 */

/***************************提交部分*****************************/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x, y, value, carry = 0;
        ListNode *h, **t = &h;
        while(l1!=NULL || l2!=NULL){
            x = getValueAndMoveNext(l1);
            y = getValueAndMoveNext(l2);
            value = x+y+carry;

            ListNode *node = new ListNode(value%10);
            *t = node;
            t = &node->next;

            carry = value/10;
        }
        if(carry > 0){
            ListNode *node = new ListNode(carry);
            *t = node;
        }
        return h;
    }

private:
    int getValueAndMoveNext(ListNode* &l){
        int x = 0;
        if(l!=NULL){
            x = l->val;
            l = l->next;
        }
        return x;
    }
};
/***************************提交部分*****************************/


//调试
int main()
{
    ListNode *h1, **t1=&h1;
    ListNode *h2, **t2=&h2;
    int x;
    while(cin>>x, x){
        ListNode *node = new ListNode(x);
        *t1 = node;
        t1 = &node->next;
    }

    while(cin>>x, x){
        ListNode *node = new ListNode(x);
        *t2 = node;
        t2 = &node->next;
    }

    Solution solution;
    ListNode *ans = solution.addTwoNumbers(h1, h2);
    while(ans){
        cout << ans->val << ' ';
        ans = ans->next;
    }
    return 0;
}
