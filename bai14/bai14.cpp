#include <iostream>
using namespace std;

const int MAX = 10; // Đặt giới hạn kích thước bàn cờ

int board[MAX][MAX];
int n;

bool isValidMove(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1);
}

void printBoard() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

bool solveKnightTour(int x, int y, int moveCount) {
    if (moveCount == n * n) {
        printBoard();
        return true;
    }

    // Các bước di chuyển có thể của quân mã
    int movesX[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int movesY[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; ++i) {
        int nextX = x + movesX[i];
        int nextY = y + movesY[i];

        if (isValidMove(nextX, nextY)) {
            board[nextX][nextY] = moveCount;
            if (solveKnightTour(nextX, nextY, moveCount + 1))
                return true;
            board[nextX][nextY] = -1; // Backtrack
        }
    }

    return false;
}

int main() {
    cout << "Nhap kich thuoc ban co (n x n): ";
    cin >> n;

    // Khởi tạo bàn cờ
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            board[i][j] = -1;

    int startX, startY;
    cout << "Nhap vi tri bat dau (x y): ";
    cin >> startX >> startY;

    // Kiểm tra nếu bài toán có thể giải
    if (!isValidMove(startX, startY)) {
        cout << "Vi tri bat dau khong hop le" << endl;
        return 0;
    }

    board[startX][startY] = 0; // Đánh dấu ô bắt đầu
    if (!solveKnightTour(startX, startY, 1))
        cout << "Khong co giai phap ton tai" << endl;

    return 0;
}
