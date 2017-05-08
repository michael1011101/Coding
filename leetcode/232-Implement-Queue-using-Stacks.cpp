#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/**
 * Title:232. Implement Queue using Stacks
    Implement the following operations of a queue using stacks.

    push(x) -- Push element x to the back of queue.
    pop() -- Removes the element from in front of queue.
    peek() -- Get the front element.
    empty() -- Return whether the queue is empty.
 */

/** solution

 */



/*************************** Submit Part *****************************/
class MyQueue {
public:
    stack<int> input, output;
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        peek();
        int tmp = output.top();
        output.pop();
        return tmp;
    }

    /** Get the front element. */
    int peek() {
        if(output.empty())
            while(!input.empty())
                output.push(input.top()), input.pop();
        return output.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
/*************************** Submit Part *****************************/

int main()
{
    MyQueue *obj = new MyQueue();
    int x;
    string op;
    while(cin >> op){
        if(op == "push"){
            cin >> x;
            (*obj).push(x);
        }
        if(op == "pop")
            cout << (*obj).pop() << endl;
        if(op == "peek")
            cout << (*obj).peek() << endl;
        if(op == "empty")
            cout << (*obj).empty() << endl;
    }
    return 0;
}
