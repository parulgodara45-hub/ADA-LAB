#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int orientation(pair<int,int> p, pair<int,int> q, pair<int,int> r) {
    long long val = (long long)(q.second - p.second) * (r.first - q.first) -
                    (long long)(q.first - p.first) * (r.second - q.second);

    if (val == 0)
        return 0;

    return (val > 0) ? 1 : 2;
}

vector<pair<int,int>> convexHull(vector<pair<int,int>>& points) {
    int n = points.size();
    int min_idx = 0;

    for (int i = 1; i < n; i++) {
        if (points[i].second < points[min_idx].second ||
            (points[i].second == points[min_idx].second &&
             points[i].first < points[min_idx].first))
            min_idx = i;
    }

    swap(points[0], points[min_idx]);

    sort(points.begin() + 1, points.end(),
        [&](const auto& a, const auto& b) {
            int o = orientation(points[0], a, b);
            if (o == 0)
                return true;
            return o == 2;
        });

    vector<pair<int,int>> hull;

    for (auto& p : points) {
        while (hull.size() > 1 &&
               orientation(hull[hull.size() - 2], hull[hull.size() - 1], p) != 2)
            hull.pop_back();

        hull.push_back(p);
    }

    return hull;
}

int main() {
    vector<pair<int,int>> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};

    vector<pair<int,int>> hull = convexHull(points);

    for (auto& p : hull)
        cout << "(" << p.first << ", " << p.second << ") ";

    return 0;
}