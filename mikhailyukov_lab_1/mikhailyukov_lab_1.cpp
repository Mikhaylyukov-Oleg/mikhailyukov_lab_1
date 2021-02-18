#include <iostream>
using namespace std;

double get_number();
double get_not_negative_number();

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "введите скорость лодки (км/ч): ";
    double boat_speed = get_not_negative_number();

    cout << "введите скорость течения реки (км/ч): ";
    double flow_speed = get_not_negative_number();

    cout << "введите расстояние между пунктами A и B (км): ";
    double distance = get_not_negative_number();

    if ((boat_speed == 0) && (flow_speed == 0)) {
        cout << "лодка будет стоять на месте";
    } else {
        if (flow_speed > boat_speed) {
            cout << "лодка не сможет плыть против течения";
        }
        else {
            if (flow_speed == boat_speed) {
                cout << "двигаясь против течения, лодка будет стоять на месте";
            }
            else {
                const double time_with_flow = distance / (boat_speed + flow_speed);
                const double time_against_flow = distance / (boat_speed - flow_speed);
                const double total_time = time_with_flow + time_against_flow;
                cout << "время в пути (в часах): " << total_time;
            }
        }
    }
    return 0;
}

double get_number()
{
    while (true)
    {
        double number;
        cin >> number;
        if (cin.fail())
        {
            cout << "ошибка: вы ввели не число\n";
            cout << "введите данные снова: ";
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else {
            cin.ignore(32767, '\n');
            return number;
        }  
    }
}

double get_not_negative_number()
{
    while (true)
    {
        double not_neg_num = get_number();
        if (not_neg_num < 0) {
            cout << "запрашиваемая величина не может быть отрицательной\n";
            cout << "введите данные снова: ";
        }
        else {
            return not_neg_num;
        }
    }
}
    