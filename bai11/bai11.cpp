#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;
};

bool compareItems(Item a, Item b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2;
}

double knapsackGreedy(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    for (const auto& item : items) {
        if (capacity >= item.weight) {
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            double fraction = (double)capacity / item.weight;
            totalValue += fraction * item.value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity;
    cout << "Nhap khoi luong tui: ";
    cin >> capacity;

    int n;
    cout << "Nhap so luong vat: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Nhap thong tin ve do vat:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Do vat " << i + 1 << " - Khoi luong: ";
        cin >> items[i].weight;

        cout << "Do vat " << i + 1 << " - Gia tri: ";
        cin >> items[i].value;
    }

    double result = knapsackGreedy(capacity, items);

    cout << "Gia tri lon nhat trong tui: " << result << endl;

    return 0;
}
