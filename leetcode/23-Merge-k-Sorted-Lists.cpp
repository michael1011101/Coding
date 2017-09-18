#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

/**
 * Title: 23. Merge k Sorted Lists
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */

/** solution
    way 1.  merge list one by one
    way 2.  use priority queue to choose the smallest node
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

/*************************** Submit Part *****************************/
struct compare{
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for(auto link : lists){
            if (link)
                q.push(link);
        }
        
        if(q.empty()) return NULL;
        
        ListNode* head = q.top();
        q.pop();
        if(head->next) q.push(head->next);
        ListNode* cur = head;
        
        while(!q.empty()){
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            if(cur->next) q.push(cur->next);
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
    vector<ListNode*> vec;
    for(int i=1; i<=x; ++i){
        ListNode* link = create(x, i);
        vec.push_back(link);
    }
    
    Solution solution;
    ListNode* head = solution.mergeKLists(vec);
    
    displayList(head);
    return 0;
}

