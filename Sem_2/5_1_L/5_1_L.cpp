#include <iostream>
#include <string>
using namespace std;

string info(int year) {
    string n[] = {
        "Крысы", "Быка", "Тигра", "Кролика",
        "Дракона", "Змеи", "Лошади", "Козы",
        "Обезьяны", "Петуха", "Собаки", "Свиньи"
    };
    int i = (year - 2020) % 12;
    if (i < 0) i += 12;
    return "Год " + n[i];
}

string info(string month) {
    if (month == "Январь" or month == "Февраль") return "Водолей/Козерог";
    if (month == "Март" or month == "Апрель") return "Овен/Рыбы";
    if (month == "Май" or month == "Июнь") return "Близнецы/Телец";
    if (month == "Июль" or month == "Август") return "Лев/Рак";
    if (month == "Сентябрь" or month == "Октябрь") return "Дева";
    if (month == "Ноябрь" or month == "Декабрь") return "Стрелец/Козерог/Скорпион";
    return "Неверный месяц";
}

int main() {
    setlocale(LC_ALL, "rus");
    cout << info(2006) << endl;
    cout << info("Сентябрь") << endl;
    return 0;
}