#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Định nghĩa một struct Activity để lưu thông tin của mỗi hoạt động
struct Activity {
    int index;   // Số thứ tự của hoạt động
    int start;   // Thời điểm bắt đầu hoạt động
    int finish;  // Thời điểm kết thúc hoạt động
};

// Hàm so sánh dùng để sắp xếp các hoạt động theo thời điểm kết thúc tăng dần
bool compare(Activity a, Activity b) {
    return (a.finish < b.finish);
}

// Hàm in ra danh sách các hoạt động đã được chọn
void printMaxActivities(vector<Activity>& activities) {
    // Sắp xếp danh sách hoạt động theo thời điểm kết thúc
    sort(activities.begin(), activities.end(), compare);
    int n = activities.size();  // Số lượng hoạt động

    cout << "Hoat dong sap xep: ";
    cout << activities[0].index << " ";  // In ra hoạt động đầu tiên

    int j = 0;
    // Duyệt qua danh sách để chọn lựa hoạt động tiếp theo
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= activities[j].finish) {
            cout << activities[i].index << " ";
            j = i;
        }
    }
}

// Hàm main là nơi bắt đầu thực hiện chương trình
int main() {
    // Khởi tạo một vector chứa thông tin của các hoạt động
    vector<Activity> activities = {
        {1, 1, 3},
        {2, 3, 4},
        {3, 4, 6},
        {4, 2, 8},
        {5, 6, 10},
        {6, 4, 13},
        {7, 10, 14},
        {8, 12, 15},
        {9, 11, 16}
    };

    // Gọi hàm để in ra danh sách hoạt động được chọn
    printMaxActivities(activities);

    return 0;
}
