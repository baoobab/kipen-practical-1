#include <iostream>
using namespace std;

int main () {
    setlocale(0, "");

    short int order = sizeof(int) * 8 - 1; // Постоянная для всех типов данных

    cout << "Навигация:" << "\n"
    << "1) Cколько памяти (в байтах) отводится под различные типы данных" << "\n"
    << "2) Двоичное представление в памяти (все разряды) целого числа" << "\n"
    << "3) Двоичное представление в памяти (все разряды) типа float" << "\n"
    << "4) Двоичное представление в памяти (все разряды) типа double" << "\n";

    while(true) {
        unsigned int mask = 1 << order;
        short int workPoint;
        cout << "Выберите пункт работы (число от 1 до 4): ";
        cin >> workPoint;

        switch (workPoint)
        {
            case 1: {
                cout << 
                "int: " << sizeof(int) << "\n" <<
                "short int: " << sizeof(short int) << "\n" <<
                "long int: " << sizeof(long int) << "\n" <<
                "float: " << sizeof(float) << "\n" <<
                "double: " << sizeof(double) << "\n" <<
                "long double: " << sizeof(long double) << "\n" <<
                "char: " << sizeof(char) << "\n" <<
                "bool: " << sizeof(bool) << "\n";
                break;
            }
            case 2: {
                int number;
                cout << "\n" << "Введите целое число: ";
                cin >> number;
                if (!cin.good()) {
                    cout << "\n" << "Вы ввели некорректное значение";
                    break;
                }

                for (int i = 0; i <= order; i++) {
                    cout << ((number & mask) ? 1: 0);
                    mask >>= 1;
                    if ((i + 1) % 8 == 0 || !i) {
                        cout << " ";
                    }
                }

                break;
            }
            case 3: {
                union {
                    int number;
                    float floatNumber;
                };

                cout << "\n" << "Введите вещественное число: ";
                cin >> floatNumber;
                if (!cin.good()) {
                    cout << "\n" << "Вы ввели некорректное значение";
                    break;
                }

                for (int i = 0; i <= order; i++) {
                    cout << ((number & mask) ? 1 : 0);
                    mask >>= 1;
                    if (i == 8 || !i) {
                        cout << " ";
                    }
                }
                break; 
            } 
            case 4: {
                union {
                    int numberArray [2] = {};
                    double doubleNumber;
                };

                cout << "\n" << "Введите вещественное число двойной точности: ";
                cin >> doubleNumber;
                if (!cin.good()) {
                    cout << "\n" << "Вы ввели некорректное значение";
                    break;
                }

                // Меняем элементы массива местами для корректного двоичного представления
                int tempElement = numberArray[1];
                numberArray[0] = numberArray[1];
                numberArray[1] = tempElement;

                for (int j = 0; j < 2; j++) {
                    for (int i = 0; i <= order; i++) {
                        cout << ((numberArray[j] & mask) ? 1: 0);
                        mask >>= 1;
                        if (!j && i == 11 || !j && !i) {
                            cout << " ";
                        }
                    }
                }
                break;   
            }       
            default: {
                cout << "\n" << "Вы ввели не число в диапазоне от 1 до 4";
                break;
            }
        }
        
        cin.clear(); // Очищаем поток ввода от возможных ошибок
        cin.sync();

        char stopFlag;
        cout << "\n" << "Продолжить работу программы? (Y/N) ";
        cin >> stopFlag;
        
        if (stopFlag != 'Y' && stopFlag != 'y') {
            break;
        }
    }

    return 0;
}
