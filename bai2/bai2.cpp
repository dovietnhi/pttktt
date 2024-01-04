#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Định nghĩa một struct để lưu trữ thông tin về mặt hàng
struct MatHang {
    char ten;
    int trongLuong;
    int giaTri;
    double tiLe;  // Tỉ lệ giá trị/trọng lượng

    // Constructor để dễ dàng tạo các đối tượng MatHang
    MatHang(char t, int tl, int gt) : ten(t), trongLuong(tl), giaTri(gt) {
        tiLe = static_cast<double>(giaTri) / trongLuong;
    }
};

// Hàm so sánh để sắp xếp mảng mặt hàng theo tỉ lệ giá trị/trọng lượng giảm dần
bool soSanh(MatHang a, MatHang b) {
    return a.tiLe > b.tiLe;
}

// Hàm giải bài toán cải túi sử dụng giải thuật tham lam
void giaiBaiToanCaiTui(vector<MatHang>& danhSachMatHang, int trongLuongTui) {
    // Sắp xếp danh sách mặt hàng theo tỉ lệ giá trị/trọng lượng giảm dần
    sort(danhSachMatHang.begin(), danhSachMatHang.end(), soSanh);

    int trongLuongConLai = trongLuongTui; // Khởi tạo trọng lượng còn lại bằng trọng lượng túi
    vector<char> matHangDuocChon; // Danh sách mặt hàng được chọn

    // Duyệt qua từng mặt hàng
    for (const auto& mh : danhSachMatHang) {
        // Nếu mặt hàng có thể fit vào túi mà không vượt quá trọng lượng còn lại
        if (mh.trongLuong <= trongLuongConLai) {
            matHangDuocChon.push_back(mh.ten); // Thêm vào danh sách mặt hàng được chọn
            trongLuongConLai -= mh.trongLuong; // Cập nhật trọng lượng còn lại
        }
    }

    // In kết quả
    cout << "Mat hang duoc chon: ";
    for (char ten : matHangDuocChon) {
        cout << ten << " ";
    }
    cout << endl;
}

int main() {
    // Khởi tạo danh sách mặt hàng từ bộ dữ liệu trong đề bài
    vector<MatHang> danhSachMatHang = {
        {'A', 18, 25},
        {'B', 15, 24},
        {'C', 10, 25}
    };

    int trongLuongTui = 20; // Trọng lượng tối đa của túi

    // Gọi hàm giải bài toán cải túi
    giaiBaiToanCaiTui(danhSachMatHang, trongLuongTui);

    return 0;
}
