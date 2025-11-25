#include <iostream>
#include <cmath>
#include <windows.h> 
#include <iomanip> 

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

 
    double sum = 0.0;
    const double epsilon = 0.001;
    int n = 1;
    double a_n;
    cout << "*** Обчислення суми ряду  ***" << endl;
    cout << "Формула: a_n = (-1)^(n+1) * (0.5)^(n-1) / (2n-1)" << endl;
    cout << "Точність (епсилон): " << epsilon << endl;
    cout << "----------------------------------------------------" << endl;

    // Цикл для обчислення членів і суми
    do {
        double numerator = pow(-1.0, n + 1) * pow(0.5, n - 1);
        double denominator = 2.0 * n - 1.0;
        a_n = numerator / denominator;

        // Перевірка умови: додавати члени, поки |a_n| >= epsilon
        if (fabs(a_n) >= epsilon) {
            sum += a_n;
            cout << "n=" << n 
                 << ", a_n=" << fixed << setprecision(6) << a_n 
                 << ", Сума=" << sum << " (Додано)" << endl;
        } else {
            // Умова |a_n| < epsilon виконана, зупиняємо цикл
            cout << "----------------------------------------------------" << endl;
            cout << "Зупинка: |a_n| = " << fixed << setprecision(6) << fabs(a_n) 
                 << " < " << epsilon << endl;
        }
        n++; 
    } while (fabs(a_n) >= epsilon); 

    cout << "----------------------------------------------------" << endl;
    cout << "Остаточна сума ряду з точністю " << epsilon << ": ";
    cout << fixed << setprecision(6) << sum << endl;

    return 0;
}
// КОМЕНТАР:
// Для обчислення суми використовується цикл do-while, який гарантує
// обчислення принаймні першого члена (n=1).
// Умова завершення циклу: |a_n| < epsilon.
// Використовується функція fabs() з бібліотеки cmath для обчислення модуля,
// а також pow() для обчислення степенів.