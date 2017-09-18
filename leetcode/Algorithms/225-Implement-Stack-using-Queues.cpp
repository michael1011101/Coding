#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

/**
 * Title:  225. Implement Stack using Queues
    Implement the following operations of a stack using queues.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    empty() -- Return whether the stack is empty.
    Notes:
    You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
    Depending on your language, queue may not be supported natively.
    You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
    You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 */

/** solution

 */


/*************************** Submit Part *****************************/
class MyStack {
    queue<int> que[2];
    int now;
public:
    /** Initialize your data structure here. */
    MyStack() {
        now = 0;
    }

    /** Push element x onto stack. */
    void push(int x) {
        que[now].push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
         int data;
         if(!que[now].empty()){
            while(que[now].size() != 1){
                que[!now].push(que[now].front());
                que[now].pop();
            }
            data = que[now].front();
            que[now].pop();
            now = !now;
        }
        return data;
    }

    /** Get the top element. */
    int top() {
        int data;
         if(!que[now].empty()){
            while(que[now].size() != 1){
                que[!now].push(que[now].front());
                que[now].pop();
            }
            data = que[now].front();
            que[!now].push(que[now].front());
            que[now].pop();
            now = !now;
        }
        return data;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que[now].empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
/*************************** Submit Part *****************************/

int main()
{

    return 0;
}

