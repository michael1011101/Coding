class MinStack {
private:
    stack<int> num, minOfNum;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(num.empty()||x<this->getMin()){
            minOfNum.push(x);
        }
        else{
            minOfNum.push(this->getMin());
        }
        num.push(x);
    }
    
    void pop() {
        if(!num.empty()){
            num.pop();
            minOfNum.pop();
        }
    }
    
    int top() {
        return num.top();
    }
    
    int getMin() {
        return minOfNum.top();
    }
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
