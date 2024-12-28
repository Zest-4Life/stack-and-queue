#include <iostream>
#include <vector>
using namespace std;

class RecentCounter {
private:
    vector<int> requests;

    int countRecent(int index, int t) {
        // Якщо індекс виходить за межі або запит занадто старий, повертаємо 0
        if (index < 0 || requests[index] < t - 3000) {
            return 0;
        }
        // Інакше рекурсивно додаємо 1 до результату попередніх запитів
        return 1 + countRecent(index - 1, t);
    }

public:
    RecentCounter() {
        requests.clear(); // Ініціалізуємо порожній список запитів
    }

    int ping(int t) {
        requests.push_back(t); // Додаємо новий запит
        return countRecent(requests.size() - 1, t); // Рахуємо кількість останніх запитів
    }
};

int main() {
    RecentCounter recentCounter;

    // Тестовий приклад
    cout << recentCounter.ping(1) << endl;    // Output: 1
    cout << recentCounter.ping(100) << endl;  // Output: 2
    cout << recentCounter.ping(3001) << endl; // Output: 3
    cout << recentCounter.ping(3002) << endl; // Output: 3

    return 0;
}
