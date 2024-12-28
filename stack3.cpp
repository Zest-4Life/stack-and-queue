#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack; // Основний стек для зберігання всіх елементів
    stack<int> minStack;  // Стек для зберігання мінімальних значень

public:
    // Конструктор
    MinStack() {}

    // Додати елемент у стек
    void push(int val) {
        mainStack.push(val);
        // Якщо minStack порожній або новий елемент менший або рівний поточному мінімуму
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    // Видалити елемент з вершини стека
    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop(); // Видалити мінімальне значення, якщо воно збігається з верхнім елементом
        }
        mainStack.pop();
    }

    // Отримати верхній елемент
    int top() {
        return mainStack.top();
    }

    // Отримати мінімальний елемент
    int getMin() {
        return minStack.top();
    }
};

// Тестовий приклад
int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // Виведе -3
    minStack.pop();
    cout << minStack.top() << endl;    // Виведе 0
    cout << minStack.getMin() << endl; // Виведе -2
    return 0;
}
