#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    double profit;
    double weight;
    double ratio;
};

double fractionalKnapsack(vector<Item>& items, double capacity) {
    sort(items.begin(), items.end(),
        [](const Item& a, const Item& b) {
            return a.ratio > b.ratio;
        });

    double totalProfit = 0;
    double remainingCapacity = capacity;

    for (const auto& item : items) {
        if (item.weight <= remainingCapacity) {
            totalProfit += item.profit;
            remainingCapacity -= item.weight;
        } else {
            double fraction = remainingCapacity / item.weight;
            totalProfit += item.profit * fraction;
            remainingCapacity = 0;
            break;
        }
    }

    return totalProfit;
}

int main() {
    vector<Item> items = {
        {60, 10, 60.0/10},
        {100, 20, 100.0/20},
        {120, 30, 120.0/30}
    };

    double capacity = 50;

    cout << fractionalKnapsack(items, capacity) << endl;

    return 0;
}