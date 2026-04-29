#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

vector<int> activitySelection(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(),
        [](const Activity& a, const Activity& b) {
            return a.finish < b.finish;
        });

    vector<int> selected;
    selected.push_back(0);

    int lastFinish = activities[0].finish;

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastFinish) {
            selected.push_back(i);
            lastFinish = activities[i].finish;
        }
    }

    return selected;
}

int main() {
    vector<Activity> activities = {
        {1, 3}, {2, 5}, {4, 7}, {1, 8}, {5, 9}, {8, 10}
    };

    vector<int> result = activitySelection(activities);

    for (int i : result)
        cout << i << " ";

    return 0;
}