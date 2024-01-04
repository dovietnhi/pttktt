#include <iostream>
using namespace std;

// Hàm này thực hiện việc đổi chỗ giữa hai giá trị a và b.
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm này thực hiện phân hoạch dãy thành hai phần, sắp xếp sao cho các phần tử bên trái pivot là nhỏ hơn hoặc bằng pivot, 
// và bên phải pivot là lớn hơn pivot.
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Hàm này là hàm đệ quy thực hiện sắp xếp dãy bằng cách chia thành các phần nhỏ và gọi lại chính nó trên các phần đó.
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Hàm main là nơi bạn nhập số phần tử n và dãy số nguyên từ bàn phím,
//  sau đó gọi hàm quickSort để sắp xếp dãy và in ra màn hình dãy gốc và dãy đã sắp xếp.
int main() {
    int n;
    cout << "Nhap vao so luong phan tu: ";
    cin >> n;

    int arr[n];
    cout << "Nhap " << n << " phan tu:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Mang goc: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    quickSort(arr, 0, n - 1);

    cout << "\nMang duoc sap xep: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
