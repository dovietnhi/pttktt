#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Hàm tìm dãy con chung dài nhất của hai dãy số
vector<int> findLongestCommonSubsequence(vector<int>& a, vector<int>& b) {
    int m = a.size();
    int n = b.size();

    // Tạo bảng lưu trữ kết quả con
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Duyệt qua từng phần tử của cả hai dãy số
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // Nếu phần tử tại vị trí i của a bằng với phần tử tại vị trí j của b
            if (a[i] == b[j]) {
                // Tăng giá trị tại ô (i+1, j+1) lên 1 so với ô (i, j)
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                // Nếu không bằng nhau, lấy giá trị lớn nhất từ ô (i, j+1) và ô (i+1, j)
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    // Tạo vector để lưu trữ kết quả dãy con chung dài nhất
    vector<int> result;
    int i = m, j = n;

    // Duyệt từ cuối bảng về đầu để lấy dãy con chung
    while (i > 0 && j > 0) {
        // Nếu phần tử tại vị trí i của a bằng với phần tử tại vị trí j của b
        if (a[i - 1] == b[j - 1]) {
            // Thêm phần tử vào vector kết quả và di chuyển lên đỉnh trái
            result.push_back(a[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            // Nếu giá trị từ trên lớn hơn giá trị từ trái, di chuyển lên trên
            i--;
        } else {
            // Nếu giá trị từ trái lớn hơn giá trị từ trên, di chuyển sang trái
            j--;
        }
    }

    // Đảo ngược vector để có thứ tự đúng của dãy con chung
    reverse(result.begin(), result.end());

    // Trả về kết quả
    return result;
}
// Hàm main để kiểm thử
int main() {
    // Khai báo và khởi tạo dãy số a và b
    vector<int> a = {3, 5, 1, 3, 5, 5, 3};
    vector<int> b = {1, 5, 3, 5, 3, 1};

    // Gọi hàm tìm dãy con chung dài nhất
    vector<int> result = findLongestCommonSubsequence(a, b);

    // In ra dãy con chung dài nhất
    cout << "Longest Common Subsequence: ";
    for (int num : result) {
        cout << num << " ";
    }

    // Kết thúc chương trình
    return 0;
}
// Hàm main nhập từ bàn phím
// int main() {
//     // Khai báo và khởi tạo dãy số a từ bàn phím
//     cout << "Nhap do dai cua day a: ";
//     int len_a;
//     cin >> len_a;

//     cout << "Nhap cac phan tu cua day a: ";
//     vector<int> a(len_a);
//     for (int i = 0; i < len_a; ++i) {
//         cin >> a[i];
//     }

//     // Khai báo và khởi tạo dãy số b từ bàn phím
//     cout << "Nhap do dai cua day b: ";
//     int len_b;
//     cin >> len_b;

//     cout << "Nhap cac phan tu cua day b: ";
//     vector<int> b(len_b);
//     for (int i = 0; i < len_b; ++i) {
//         cin >> b[i];
//     }

//     // Gọi hàm tìm dãy con chung dài nhất
//     vector<int> result = findLongestCommonSubsequence(a, b);

//     // In ra dãy con chung dài nhất
//     cout << "Day con chung dai nhat: ";
//     for (int num : result) {
//         cout << num << " ";
//     }

//     return 0;
// }

// Tạo bảng dp: Bảng này được sử dụng để lưu trữ kết quả con của từng cặp con dãy và được khởi tạo với các giá trị 0.

// Duyệt qua từng phần tử của dãy a và dãy b: Vòng lặp này sẽ duyệt qua từng phần tử của cả hai dãy số và điền giá trị vào bảng dp dựa trên quy tắc đã mô tả trong bài toán.

// Reconstruct dãy con chung dài nhất: Sử dụng thông tin từ bảng dp để tái tạo dãy con chung dài nhất.

// In ra kết quả: In ra dãy con chung dài nhất tìm được.