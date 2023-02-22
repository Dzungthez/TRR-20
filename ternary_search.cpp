#include <iostream>

using namespace std;
int ternarySearch(int arr[], int left, int right, int key) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        // Kiểm tra nếu key có nằm ở mid1 hoặc mid2
        if (arr[mid1] == key) {
            return mid1;
        }
        if (arr[mid2] == key) {
            return mid2;
        }

        // Nếu key nằm ở khoảng giữa mid1 và mid2
        if (key < arr[mid1]) {
            return ternarySearch(arr, left, mid1 - 1, key);
        } else if (key > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, right, key);
        } else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
        }
    }
    return -1;
}
int main()
{
    int n; cin >> n; // nhap so luong phan tu cua day
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // nhap vao day so (tang a)
    }
    int key; cin >> key; // nhap vao ki tu can search
    cout << "vi tri cua " << key << " trong day la: " << ternarySearch(a, 0, n-1, key);
delete a;

return 0;
}