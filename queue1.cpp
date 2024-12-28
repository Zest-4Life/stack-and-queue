#include <iostream>
#include <string>
using namespace std;

// Рекурсивна функція для пошуку першого унікального символу
int findFirstUnique(const string& s, int index = 0) {
    // Базовий випадок: якщо індекс перевищує довжину рядка, повертаємо -1
    if (index >= s.length()) {
        return -1;
    }

    // Перевіряємо, чи символ унікальний
    char current = s[index];
    if (s.find_first_of(current) == index && s.find_last_of(current) == index) {
        return index; // Якщо символ унікальний, повертаємо його індекс
    }

    // Рекурсивно переходимо до наступного символу
    return findFirstUnique(s, index + 1);
}

int main() {
    // Приклади
    string s1 = "leopard";
    string s2 = "loveleopard";
    string s3 = "aabb";

    cout << "Input: " << s1 << " Output: " << findFirstUnique(s1) << endl;
    cout << "Input: " << s2 << " Output: " << findFirstUnique(s2) << endl;
    cout << "Input: " << s3 << " Output: " << findFirstUnique(s3) << endl;

    return 0;
}
