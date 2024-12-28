#include <iostream>
#include <string>

using namespace std;

// Рекурсивна функція для перевірки валідності дужок
bool isValidRecursive(const string& s, int index, string stack) {
    // Базовий випадок: якщо всі символи оброблені
    if (index == s.length()) {
        return stack.empty();
    }

    char current = s[index];

    // Якщо символ відкриваюча дужка, додаємо її до "стека"
    if (current == '(' || current == '{' || current == '[') {
        return isValidRecursive(s, index + 1, stack + current);
    }

    // Якщо символ закриваюча дужка, перевіряємо відповідність
    if (current == ')') {
        if (!stack.empty() && stack.back() == '(') {
            stack.pop_back();
            return isValidRecursive(s, index + 1, stack);
        }
        else {
            return false;
        }
    }
    else if (current == '}') {
        if (!stack.empty() && stack.back() == '{') {
            stack.pop_back();
            return isValidRecursive(s, index + 1, stack);
        }
        else {
            return false;
        }
    }
    else if (current == ']') {
        if (!stack.empty() && stack.back() == '[') {
            stack.pop_back();
            return isValidRecursive(s, index + 1, stack);
        }
        else {
            return false;
        }
    }

    return false; // Невідомий символ (не повинен траплятися за умовою задачі)
}

bool isValid(string s) {
    return isValidRecursive(s, 0, "");
}

int main() {
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;

    if (isValid(s)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}
