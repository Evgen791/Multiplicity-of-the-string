#include <iostream>
using namespace std;

// Функция IsKPeriodic проверяет, является ли строка s кратной числу k.
// Возвращает true, если строка является кратной k, и false - в противном случае.
bool IsKPeriodic(string s, int k) {
    if (k <= 0 || s.length() % k != 0) { // если k меньше или равно 0 или длина строки не кратна k
        return false; // возвращаем false
    }
    for (int i = 0; i < k; i++) { // проверяем каждый символ в интервале [0, k)
        char c = s[i];
        for (int j = i + k; j < s.length(); j += k) { // с шагом k перебираем все символы начиная с i + k
            if (s[j] != c) { // нашли несовпадение, значит строка не кратна k
                return false; // возвращаем false
            }
        }
    }
    return true; // если все проверки прошли успешно, то возвращаем true
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s); // запрашиваем ввод строки с клавиатуры

    int k = 1; // начнем перебор с k = 1
    int max_k = s.length() / 2; // максимальное значение k равно половине длины строки
    while (k <= max_k && !IsKPeriodic(s, k)) { // пока не нашли кратность и k не превысило максимальное, проверяем все значения k
        k++;
    }

    if (k > max_k) { // если не нашли кратность, выводим сообщение об этом
        cout << "No periodicity found";
    } else {
        cout << s << " is " << k << "-periodic"; // иначе выводим строку и найденное значение k
    }
    return 0;
}