#include <iostream>
#include <vector>
using namespace std;

// Khai báo đệ quy để tìm các dãy con có tổng bằng M.
void findSubsequences(vector<int>& sequence, vector<int>& current, size_t index, int target) {
    if (index == sequence.size()) {
        int sum = 0;
        for (int num : current) {
            sum += num;
        }
        if (sum == target) {
            cout << "Tim thay day con: ";
            for (int num : current) {
                cout << num << " ";
            }
            cout << endl;
        }
        return;
    }

    // Bao gồm phần tử hiện tại trong chuỗi tiếp theo
    current.push_back(sequence[index]);
    findSubsequences(sequence, current, index + 1, target);

    // Loại trừ phần tử hiện tại khỏi chuỗi con
    current.pop_back();
    findSubsequences(sequence, current, index + 1, target);
}

// Hàm main là nơi bắt đầu thực thi chương trình.
int main() {
    int m;
    cout << "Nhap gia tri M: ";
    cin >> m;

    int n;
    cout << "Nhap so luong day so: ";
    cin >> n;

    vector<int> sequence(n);
    cout << "Nhap gia tri day so\n ";
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    // Tạo một vector current để lưu trữ dãy con tạm thời và gọi hàm findSubsequences để tìm các dãy con có tổng bằng M.
    vector<int> current;
    findSubsequences(sequence, current, 0, m);

    return 0;
}
