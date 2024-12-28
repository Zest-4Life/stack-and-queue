#include <iostream>
using namespace std;

class MyCircularQueue {
private:
    int* queue;
    int front;
    int rear;
    int size;
    int capacity;

public:
    // Конструктор для ініціалізації об'єкта із заданим розміром k
    MyCircularQueue(int k) {
        capacity = k;
        queue = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Деструктор для звільнення пам'яті
    ~MyCircularQueue() {
        delete[] queue;
    }

    // Додавання елемента в циклічну чергу
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
        return true;
    }

    // Видалення елемента з циклічної черги
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) { // Якщо видаляємо останній елемент
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }
        size--;
        return true;
    }

    // Отримання переднього елемента
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return queue[front];
    }

    // Отримання останнього елемента
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return queue[rear];
    }

    // Перевірка, чи черга порожня
    bool isEmpty() {
        return size == 0;
    }

    // Перевірка, чи черга заповнена
    bool isFull() {
        return size == capacity;
    }
};

// Тестування реалізації
int main() {
    MyCircularQueue myCircularQueue(3);
    cout << boolalpha; // Вивід true/false замість 1/0
    cout << myCircularQueue.enQueue(1) << endl; // true
    cout << myCircularQueue.enQueue(2) << endl; // true
    cout << myCircularQueue.enQueue(3) << endl; // true
    cout << myCircularQueue.enQueue(4) << endl; // false
    cout << myCircularQueue.Rear() << endl;     // 3
    cout << myCircularQueue.isFull() << endl;   // true
    cout << myCircularQueue.deQueue() << endl;  // true
    cout << myCircularQueue.enQueue(4) << endl; // true
    cout << myCircularQueue.Rear() << endl;     // 4
    return 0;
}
