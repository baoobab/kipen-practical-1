#include <iostream>
using namespace std;

int main () {
    setlocale(0, "");

    while(true) {
        cout << "Выберите пункт работы (число от 1 до 4): " << "\n";
        short int workPoint;
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
        }
        
        cin.clear(); // Очищаем поток ввода от возможных ошибок
        cout << "\n" << "Продолжить работу программы? (Y/N) ";
        char stopFlag;
        cin >> stopFlag;
        
        if (stopFlag != 'Y' && stopFlag != 'y') {
            break;
        }
    }

    return 0;
}
