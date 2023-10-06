#include <iostream>
using namespace std;

int main () {
    setlocale(0, "");

    // ������� ���������� ��� ���� ����� ������
    short int order = sizeof(int) * 8 - 1;
    unsigned int mask = 1 << order;

    while(true) {
        cout << "�������� ����� ������ (����� �� 1 �� 4): " << "\n";
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
            case 2: {
                int number;
                cout << "\n" << "������� ����� �����: ";
                cin >> number;

                for (int i = 0; i <= order; i++) {
                    cout << ((number & mask) ? 1: 0);
                    mask >>= 1;
                    if (!i) {
                        cout << " ";
                    }
                    if ((i + 1) % 8 == 0) {
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

                cout << "\n" << "������� ������������ �����: ";
                cin >> floatNumber;

                for (int i = 0; i <= order; i++) {
                    cout << ((number & mask) ? 1: 0);
                    mask >>= 1;
                    if (!i) {
                        cout << " ";
                    }
                    if (i == 8) {
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

                cout << "\n" << "������� ������������ ����� ������� ��������: ";
                cin >> doubleNumber;

                // ������ �������� ������� ������� ��� ����������� ��������� �������������
                int tempElement = numberArray[1];
                numberArray[0] = numberArray[1];
                numberArray[1] = tempElement;

                for (int j = 0; j < 2; j++) {
                    for (int i = 0; i <= order; i++) {
                        cout << ((numberArray[j] & mask) ? 1: 0);
                        mask >>= 1;
                        if (!j && !i) {
                            cout << " ";
                        }
                        if (!j && i == 11) {
                            cout << " ";
                        }
                    }
                }
                break;   
            }       
            default: {
                cout << "\n" << "�� ����� �� ����� � ��������� �� 1 �� 4";
                break;
            }
        }
        
        cin.clear(); // ������� ����� ����� �� ��������� ������
        cout << "\n" << "���������� ������ ���������? (Y/N) ";
        char stopFlag;
        cin >> stopFlag;
        
        if (stopFlag != 'Y' && stopFlag != 'y') {
            break;
        }
    }

    return 0;
}
