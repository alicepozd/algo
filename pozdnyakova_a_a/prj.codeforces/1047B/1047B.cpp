    #include <iostream>
     
     
    int main() {
        int n;
        std::cin >> n;
        int min_side_len = 0;
        for (int i = 0; i < n; ++i) {
            int x, y;
            std::cin >> x >> y;
            if (min_side_len == 0 || min_side_len < x + y) {
                min_side_len = x + y;
            }
        }
        std::cout << min_side_len;
        return 0;
    }