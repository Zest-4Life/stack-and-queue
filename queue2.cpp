#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2; // Дві черги для реалізації стека

public:
    // Розміщує елемент x на вершину стека.
    void push(int x) {
        q2.push(x); // Додаємо новий елемент у q2
        // Переміщуємо всі елементи з q1 до q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Міняємо місцями q1 та q2
        swap(q1, q2);
    }

    // Вилучає елемент у верхній частині стека та повертає його.
    int pop() {
        if (q1.empty()) throw runtime_error("Stack is empty");
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    // Повертає елемент у верхній частині стека.
    int top() {
        if (q1.empty()) throw runtime_error("Stack is empty");
        return q1.front();
    }

    // Повертає true, якщо стек порожній, і false в іншому випадку.
    bool empty() {
        return q1.empty();
    }
};

// Приклад використання
int main() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    cout << "Top element: " << myStack.top() << endl; // Виведе 2
    cout << "Popped element: " << myStack.pop() << endl; // Виведе 2
    cout << "Is stack empty? " << (myStack.empty() ? "Yes" : "No") << endl; // Виведе No
    return 0;
}
