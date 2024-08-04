#include <iostream>
#include <cmath>

// Hàm tính tổ hợp chập K của N
long long tinhToHop(int N, int K) {
    long double result = 1.0;
    for (int i = 1; i <= K; ++i) {
        result *= (N - K + i);
        result /= i;
    }
    return std::round(result);
}

int main() {
    int N;
    std::cout << "N: ";
    std::cin >> N;

    // Số lần bắt tay
    long long handshake_count = combination(N, 2);

    std::cout << "T: " << handshake_count << std::endl;

    return 0;
}
