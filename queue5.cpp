#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Функція для перевірки, чи можна замінити підрядок у target на stamp
bool canStamp(const string& stamp, string& target, int pos) {
    bool stamped = false;
    for (int i = 0; i < stamp.size(); i++) {
        if (target[pos + i] == '?') continue;
        if (target[pos + i] != stamp[i]) return false;
        stamped = true;
    }
    return stamped;
}

// Функція для виконання штампування
void doStamp(const string& stamp, string& target, int pos) {
    for (int i = 0; i < stamp.size(); i++) {
        target[pos + i] = '?';
    }
}

// Рекурсивна функція для розв'язання задачі
bool solve(string& stamp, string& target, vector<int>& result, int depth = 0) {
    if (depth > 10 * target.size()) return false; // Ліміт на кількість кроків
    bool changed = false;
    for (int i = 0; i <= target.size() - stamp.size(); i++) {
        if (canStamp(stamp, target, i)) {
            doStamp(stamp, target, i);
            result.push_back(i);
            changed = true;
        }
    }
    if (target == string(target.size(), '?')) return true; // Успішне завершення
    return changed ? solve(stamp, target, result, depth + 1) : false;
}

// Основна функція
vector<int> movesToStamp(string stamp, string target) {
    vector<int> result;
    if (solve(stamp, target, result)) {
        reverse(result.begin(), result.end());
        return result;
    }
    return {};
}

int main() {
    string stamp = "abc", target = "ababc";
    vector<int> result = movesToStamp(stamp, target);

    if (!result.empty()) {
        cout << "Output: [";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i < result.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    else {
        cout << "Output: []" << endl;
    }

    return 0;
}
