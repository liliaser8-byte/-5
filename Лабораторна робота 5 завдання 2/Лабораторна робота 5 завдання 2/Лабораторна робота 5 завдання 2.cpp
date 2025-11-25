
#include <windows.h>
#include <iostream>
#include <cmath>

    using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 12;
    long long a[N];              // Масив для збереження 12 значень

    a[0] = 2;
    a[1] = 3;
    for (int i = 2; i < N; i++) {
        a[i] = 3 * a[i - 1] + 7 * a[i - 2];
    }

    //  Вивід усіх 12 елементів
 
    cout << "12 елементів послідовності (a[0] до a[11]):" << endl;
    for (int i = 0; i < N; i++) {
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    return 0;
}