#include <iostream>
#include <string>
using namespace std;

// Рекурсивна функція для пошуку найдовшого дійсного підрядка
int findLongestValid(string s, int start, int end) {
    // Базовий випадок: якщо довжина підрядка менше 2, він не може бути дійсним
    if (end - start < 2) {
        return 0;
    }

    int balance = 0; // Лічильник балансу дужок
    int maxLength = 0; // Максимальна довжина

    for (int i = start; i < end; ++i) {
        if (s[i] == '(') {
            balance++;
        }
        else {
            balance--;
        }

        // Якщо баланс стає нулем, це означає, що підрядок правильний
        if (balance == 0) {
            maxLength = max(maxLength, i - start + 1);
        }
        // Якщо баланс від'ємний, дужки не можуть бути дійсними
        if (balance < 0) {
            break;
        }
    }

    // Якщо баланс позитивний, перевіряємо праву частину
    if (balance > 0) {
        return max(maxLength, findLongestValid(s, start + 1, end));
    }

    // Якщо баланс негативний, перевіряємо ліву частину
    return max(maxLength, findLongestValid(s, start, end - 1));
}

int longestValidParentheses(string s) {
    return findLongestValid(s, 0, s.length());
}

int main() {
    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    int result = longestValidParentheses(s);
    cout << "Longest valid parentheses substring length: " << result << endl;

    return 0;
}
