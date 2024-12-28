#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Рекурсивна функція для обчислення максимального ковзаючого вікна
vector<int> slidingWindowMax(const vector<int>& nums, int k, int start = 0) {
    // Якщо залишилося менше елементів, ніж розмір вікна, повертаємо порожній результат
    if (start + k > nums.size()) {
        return {};
    }

    // Знайти максимум для поточного вікна
    int currentMax = *max_element(nums.begin() + start, nums.begin() + start + k);

    // Виклик рекурсії для наступного вікна
    vector<int> result = slidingWindowMax(nums, k, start + 1);

    // Додати поточний максимум на початок результату
    result.insert(result.begin(), currentMax);

    return result;
}

int main() {
    // Приклади вводу
    vector<int> nums1 = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k1 = 3;
    vector<int> nums2 = { 1 };
    int k2 = 1;

    // Обчислення максимального ковзаючого вікна
    vector<int> result1 = slidingWindowMax(nums1, k1);
    vector<int> result2 = slidingWindowMax(nums2, k2);

    // Виведення результатів
    cout << "Result 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
