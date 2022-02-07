    #include <iostream>
    #include <vector>
     
     
    double get_expectation(const std::vector<std::vector<double>> &prob, long long t) {
        double expectation = 0;
        for (int i = 0; i < prob.size(); ++i) {
            expectation += i * prob[i][t];
        }
        return expectation;
    }
     
     
    double get_prob(long long n, double p, long long t) {
        std::vector<std::vector<double>> prob (n + 1, std::vector<double>(t + 1, 0));
        prob[0][0] = 1; // dp init
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= t; ++j) {
                if (i == 0) {
                    prob[i][j] = prob[i][j - 1] * (1 - p);
                } else if (i == n) {
                    prob[i][j] = prob[i][j - 1] + prob[i - 1][j - 1] * p;
                }
                else {
                    prob[i][j] = prob[i][j - 1] * (1 - p) + prob[i - 1][j - 1] * p; // prob for i persons on j second
                }
            }
        }
        return get_expectation(prob, t);
    }
     
     
    int main() {
        long long n, t;
        double p;
        std::cin >> n >> p >> t;
        std::cout << get_prob(n, p, t);
        return 0;
    }