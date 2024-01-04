#include <iostream>
using namespace std;
// #include <iostream>: Đây là một thư viện trong C++ cho việc nhập xuất dữ liệu. Nó chứa các đối tượng như cin (để nhập) và cout (để xuất).
// using namespace std;: Dòng này giúp bạn không cần phải sử dụng tiền tố std:: trước mỗi lệnh cin và cout.
// Chia để trị
// Hàm này tính giai thừa n! bằng phương pháp chia để trị.
// Nếu n bằng 0 hoặc 1, n! là 1.
// Ngược lại, tính n! bằng cách chia n thành hai phần, tính nửa phần và nhân lại. Nếu n là số chẵn, sẽ nhân bình phương của nửa phần. Ngược lại, sẽ nhân n với bình phương của nửa phần.
int factorialDivideConquer(int n) {
    if (n == 0 || n == 1)
        return 1;
    else {
        int temp = factorialDivideConquer(n / 2);
        if (n % 2 == 0)
            return temp * temp;
        else
            return n * temp * temp;
    }
}

// Quy hoạch động
// Hàm này tính giai thừa n! bằng phương pháp quy hoạch động.
// Tạo một mảng dp có kích thước là n + 1 để lưu trữ các giá trị đã tính.
// Khởi tạo dp[0] và dp[1] là 1 vì 0! và 1! đều bằng 1.
// Sử dụng vòng lặp để tính giá trị của dp[i] từ 2 đến n bằng cách nhân i với dp[i-1].
int factorialDynamicProgramming(int n) {
    int dp[n + 1];
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; ++i)
        dp[i] = i * dp[i - 1];

    return dp[n];
}
// Khai báo biến nguyên n để lưu giá trị nhập từ bàn phím.
// Sử dụng cout để yêu cầu người dùng nhập giá trị n.
// Sử dụng cin để nhận giá trị n từ bàn phím.
// Gọi và in kết quả của hai hàm factorialDivideConquer và factorialDynamicProgramming với giá trị n đã nhập.
int main() {
    // int n = 5; // Bạn có thể thay đổi giá trị n tùy ý

    //Nhập từ bàn phím
    int n;
    cout << "Nhap gia tri n: ";
    cin >> n;

    cout << "Chia de tri: " << factorialDivideConquer(n) << endl;
    cout << "Quy hoach dong: " << factorialDynamicProgramming(n) << endl;

    return 0;
}
