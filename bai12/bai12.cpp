#include <iostream>
#include <vector>
using namespace std;
// #include <iostream>: Sử dụng để đọc và ghi từ bàn phím và ra màn hình.
// #include <vector>: Sử dụng để sử dụng cấu trúc dữ liệu vector.
// using namespace std;: Giúp sử dụng các thành phần của thư viện chuẩn (std) mà không cần thêm tiền tố std::

// Tham số hàm:
// w: Khối lượng túi có thể chứa.
// weight: Mảng chứa khối lượng của các đồ vật.
// value: Mảng chứa giá trị tương ứng của các đồ vật.
// n: Số loại đồ vật.
// Bảng dp:
// Tạo một bảng 2 chiều dp để lưu giữ giá trị tối đa có thể đạt được với i đồ vật và j khối lượng túi (dp[i][j] là giá trị tối đa).
// Vòng lặp:
// Sử dụng hai vòng lặp for để duyệt qua từng đồ vật và từng khối lượng túi.
// Sử dụng câu điều kiện để quyết định xem có nên chọn đồ vật thứ i vào túi hay không.
// Cập nhật giá trị dp[i][j] dựa trên giá trị tốt nhất từ các trạng thái trước đó.
int knapsack(int w, vector<int>& weight, vector<int>& value, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= w; ++j) {
            if (weight[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][w];
}

// Nhập dữ liệu từ bàn phím:
// Sử dụng cin để nhập giá trị của n và w từ bàn phím.
// Tạo mảng và nhập giá trị cho từng đồ vật:
// Sử dụng vòng lặp for để nhập giá trị cho từng đồ vật.
// Gọi hàm knapsack và hiển thị kết quả:
// Gọi hàm knapsack với các giá trị đã nhập và hiển thị kết quả lớn nhất có thể đạt được.
int main() {
    int n, w;

    cout << "Nhap so loai do vat (n): ";
    cin >> n;

    cout << "Nhap khoi luong tui co the chua (w): ";
    cin >> w;

    vector<int> weight(n);
    vector<int> value(n);

    cout << "Nhap khoi luong va gia tri cho tung loai do vat:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Do vat " << i + 1 << " - Khoi luong: ";
        cin >> weight[i];
        cout << "Do vat " << i + 1 << " - Gia tri: ";
        cin >> value[i];
    }

    int result = knapsack(w, weight, value, n);

    cout << "Gia tri lon nhat co the dat duoc: " << result << endl;

    return 0;
}
