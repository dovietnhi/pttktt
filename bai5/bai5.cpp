#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm đệ quy để đếm số cách phân tích n thành tổng các số nguyên dương
void countWays(int n, vector<int>& current, int& count) {
    // Nếu n trở thành 0, có một cách phân tích mới được tìm thấy
    if (n == 0) {
        count++;
        return;
    }

    // Duyệt qua tất cả các số từ 1 đến n
    for (int i = 1; i <= n; i++) {
        // Thêm số i vào mảng current
        current.push_back(i);
        // Gọi đệ quy với n giảm đi giá trị vừa thêm
        countWays(n - i, current, count);
        // Loại bỏ số vừa thêm để thử số tiếp theo
        current.pop_back();
    }
}

int main() {
    int n;
    // Nhập giá trị n từ người dùng
    cout << "Nhap so nguyen n (< 100): ";
    cin >> n;

    // Kiểm tra giá trị n có hợp lệ hay không
    if (n >= 100 || n < 1) {
        cout << "Nhap n khong hop le.";
        return 1;
    }

    // Khởi tạo mảng để lưu các số nguyên dương
    vector<int> current;
    // Biến đếm số cách phân tích
    int count = 0;

    // Gọi hàm đệ quy để đếm số cách phân tích
    countWays(n, current, count);

    // In ra kết quả
    cout << "So cach phan tich " << n << " la: " << count << endl;

    return 0;
}
// Khởi tạo thư viện và namespace:

// #include <iostream>: Sử dụng để đọc và in dữ liệu.
// #include <vector>: Sử dụng để sử dụng cấu trúc dữ liệu vector.
// #include <algorithm>: Sử dụng để sử dụng hàm sort.
// Khai báo hàm đệ quy countWays:

// Hàm này được thiết kế để đệ quy và đếm số cách phân tích số n.
// Hàm đệ quy countWays:

// Điều kiện dừng: Nếu n trở thành 0, tăng biến count lên và thoát khỏi hàm.
// Duyệt qua tất cả các số từ 1 đến n.
// Thêm số đó vào mảng current.
// Gọi đệ quy với n giảm đi giá trị vừa thêm.
// Loại bỏ số vừa thêm để thử số tiếp theo.
// Hàm main:

// Nhập giá trị n từ người dùng.
// Kiểm tra giá trị n có hợp lệ hay không.
// Khởi tạo mảng current để lưu các số nguyên dương và biến đếm count.
// Gọi hàm đệ quy countWays để đếm số cách phân tích.
// In ra kết quả.