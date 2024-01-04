#include <iostream>
using namespace std;

// Hàm thực hiện đổi tiền xu
void doiTienXu(int n) {
    // Mảng chứa giá trị của các đồng xu
    int coins[] = {5000, 2000, 1000, 500};
    
    // Số loại đồng xu
    int numCoins = sizeof(coins) / sizeof(coins[0]);

    // Duyệt qua từng loại đồng xu
    for (int i = 0; i < numCoins; i++) {
        // Lặp đến khi số tiền còn lại không đủ để đổi loại đồng xu hiện tại
        while (n >= coins[i]) {
            // In ra giá trị đồng xu và giảm số tiền còn lại tương ứng
            cout << coins[i] << " ";
            n -= coins[i];
        }
    }
}

// Hàm main để chạy chương trình
int main() {
    int n;
    // Nhập số tiền cần đổi từ người dùng
    cout << "Nhap so tien can doi: ";
    cin >> n;

    // Gọi hàm đổi tiền xu và in kết quả
    cout << "Cac dong xu can dung la: ";
    doiTienXu(n);

    return 0;
}
