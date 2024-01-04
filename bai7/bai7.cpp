#include <iostream>
using namespace std;

// Hàm đệ quy để đếm số cách phân tích n thành tổng các số nguyên dương
int countWays(int n, int currentNum) {
    if (n == 0) return 1; // Nếu đã phân tích thành công, trả về 1
    if (n < 0 || currentNum > n) return 0; // Nếu không tìm thấy cách phân tích, trả về 0

    // Thử mọi khả năng từ currentNum đến n
    int count = 0;
    for (int i = currentNum; i <= n; ++i) {
        count += countWays(n - i, i + 1); // Đệ quy với số còn lại và currentNum được cập nhật
    }
    return count;
}

int main() {
    int n;
    cout << "Nhap so nguyen n (n <= 100): ";
    cin >> n;

    if (n <= 100) {
        int result = countWays(n, 1); // Gọi hàm đệ quy để đếm số cách phân tích
        cout << "So cach phan tich " << n << " la: " << result << endl;
    } else {
        cout << "Nhap n khong hop le!" << endl;
    }

    return 0;
}
// Hàm countWays:

// Hàm này sử dụng kỹ thuật đệ quy để đếm số cách phân tích số n thành tổng các số nguyên dương, bắt đầu từ currentNum.
// Nếu n đã được phân tích thành công (n = 0), hàm trả về 1.
// Nếu n âm hoặc currentNum lớn hơn n, hàm trả về 0 vì không có cách phân tích.
// Hàm main:

// Yêu cầu người dùng nhập số nguyên n.
// Kiểm tra nếu n lớn hơn 100 thì thông báo là "Nhap n khong hop le!".
// Nếu n hợp lệ, gọi hàm countWays để đếm số cách phân tích và hiển thị kết quả.
// Lưu ý rằng giải thuật này sử dụng đệ quy và có thể không hiệu quả với các giá trị lớn của n. Có thể cần cân nhắc sử dụng các phương pháp tối ưu hóa nếu bạn muốn xử lý các giá trị lớn.