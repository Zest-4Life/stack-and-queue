#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;

    void transferElements() {
        // Transfer elements from inputStack to outputStack only if outputStack is empty
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        transferElements();
        int topElement = outputStack.top();
        outputStack.pop();
        return topElement;
    }

    int peek() {
        transferElements();
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    cout << "Peek: " << myQueue.peek() << endl; // Returns 1
    cout << "Pop: " << myQueue.pop() << endl;  // Returns 1
    cout << "Empty: " << (myQueue.empty() ? "true" : "false") << endl; // Returns false

    return 0;
}
