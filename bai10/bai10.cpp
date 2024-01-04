#include <iostream>
#include <vector>

void Merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        Merge(arr, left, mid, right);
    }
}

int main() {
     int n;

    // Nhập giá trị n từ bàn phím
    std::cout << "Nhap gia tri n: ";
    std::cin >> n;

    // Tạo mảng và nhập giá trị cho mảng từ bàn phím
    std::vector<int> arr(n);
    std::cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    std::cout << "Mang goc: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    MergeSort(arr, 0, arr.size() - 1);

    std::cout << "\nMang sap xep: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
