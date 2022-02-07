    #include <iostream>
    #include <vector>
     
     
    uint64_t count_combinations(const std::vector<uint64_t> &points, uint64_t d) {
        uint64_t combinations_number = 0;
        uint64_t left = 0;
        for (uint64_t right = 0; right < points.size(); ++right) {
            while (points[right] - points[left] > d) {
                ++left;
            }
            combinations_number += (right - left) * (right - left - 1) / 2; // number of combinations with maximum point in place right
        }
        return combinations_number;
    }
     
     
    int main() {
        uint64_t n, d;
        std::cin >> n >> d;
        std::vector<uint64_t> points;
        for (uint64_t i = 0; i < n; ++i) {
            uint64_t point;
            std::cin >> point;
            points.push_back(point);
        }
        std::cout << count_combinations(points, d);
        return 0;
    }