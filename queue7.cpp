#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> nums;
vector<int> dp; // Для мемоізації результатів
int k;

// Рекурсивна функція для обчислення максимальної суми
int maxSubsequenceSum(int index) {
    if (index >= nums.size()) return INT_MIN; // Вихід за межі масиву
    if (dp[index] != INT_MIN) return dp[index]; // Якщо вже обчислено

    int maxSum = nums[index]; // Початкова сума — поточний елемент
    for (int j = 1; j <= k; ++j) {
        if (index + j < nums.size()) {
            maxSum = max(maxSum, nums[index] + maxSubsequenceSum(index + j));
        }
    }
    dp[index] = maxSum;
    return dp[index];
}

int main() {
    // Вхідні дані
    nums = { 10, -2, -10, -5, 20 };
    k = 2;

    // Ініціалізація dp
    dp = vector<int>(nums.size(), INT_MIN);

    // Обчислення максимального результату
    int result = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
        result = max(result, maxSubsequenceSum(i));
    }

    // Виведення результату
    cout << "Maximum subsequence sum: " << result << endl;
    return 0;
}
