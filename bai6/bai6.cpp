#include <iostream>

// Sử dụng thư viện <iostream> để sử dụng các hàm nhập và xuất của C++.
// const int N = 8: Khai báo hằng số N để đại diện cho số lượng con hậu và kích thước bàn cờ.
// int queens[N]: Mảng lưu trữ vị trí của các con hậu trên cột tương ứng với hàng.
const int N = 8; 
int queens[N];

// isSafe kiểm tra xem có thể đặt một con hậu vào vị trí (row, col) hay không.
// Duyệt qua các hàng đã đặt hậu trước đó (i < row).
// Kiểm tra xem con hậu ở hàng i có tấn công được vị trí (row, col) không.
bool isSafe(int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (queens[i] == col || queens[i] - i == col - row || queens[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

// solve là hàm chính thực hiện thuật toán quay lui.
// Nếu đã đặt hết 8 con hậu (row == N), in ra một cách đặt hậu.
// Duyệt qua các cột trong hàng row, kiểm tra và đặt hậu nếu an toàn, sau đó đệ quy để đặt hậu tiếp theo ở hàng tiếp theo.
void solve(int row) {
    if (row == N) {
        // In kết quả
        for (int i = 0; i < N; ++i) {
            std::cout << queens[i] << " ";
        }
        std::cout << std::endl;
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(row, col)) {
            queens[row] = col;
            solve(row + 1);
        }
    }
}

// Hàm main chỉ gọi hàm solve để bắt đầu giải bài toán.
// Thông qua đệ quy, tất cả các cách đặt hậu hợp lệ sẽ được liệt kê.
int main() {
    solve(0);
    return 0;
}
