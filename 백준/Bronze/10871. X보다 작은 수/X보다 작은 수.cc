#include<iostream>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, x;
    std::cin >> n >> x;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (a[i] < x) std::cout << a[i] << ' ';
    }
    delete[] a;
}