#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    float x;
    float y;
public:
    void init(float a, float b) {
        x = a;
        y = b;
    }

    void read() {
        cout << "Задайте координаты точки" << endl;
        cout << "x: "; cin >> x;
        cout << "y: "; cin >> y;
    }

    float calculate_distance() {
        return sqrt(x * x + y * y);
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Point point;

    point.read();

    float distance = point.calculate_distance();
    cout << "Расстояние до начала координат: " << distance << endl;

    return 0;
}