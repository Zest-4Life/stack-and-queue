#include <iostream>
#include <string>
using namespace std;

string decodeString(const string& s, int& index) {
    string result;
    int k = 0;

    // Пройдемо по кожному символу рядка
    while (index < s.size()) {
        char c = s[index];

        // Якщо символ - цифра, то збираємо число
        if (isdigit(c)) {
            k = k * 10 + (c - '0');
        }
        // Якщо символ - відкриваюча дужка, то викликаємо рекурсію для внутрішнього рядка
        else if (c == '[') {
            index++;  // Пропускаємо символ '['
            string decodedPart = decodeString(s, index);
            while (k--) {  // Повторюємо декодований рядок k разів
                result += decodedPart;
            }
        }
        // Якщо символ - закриваюча дужка, завершимо обробку внутрішнього рядка
        else if (c == ']') {
            index++;  // Пропускаємо символ ']'
            return result;
        }
        // Якщо символ - буква, додаємо її до результату
        else {
            result += c;
        }
        index++;
    }

    return result;
}

string decodeString(const string& s) {
    int index = 0;
    return decodeString(s, index);
}

int main() {
    string s;

    // Введення рядка
    cout << "Enter the encoded string: ";
    cin >> s;

    // Виклик функції для декодування
    string decoded = decodeString(s);

    // Виведення результату
    cout << "Decoded string: " << decoded << endl;

    return 0;
}
