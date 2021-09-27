#include <iostream>

using namespace std;

class Point {
public:
    Point(int x, int y) : x_(x), y_(y) {}

    Point operator +(const Point &other) {
        return Point(x_ + other.x_, y_ + other.y_);
    }

    int getX() {
        return x_;
    }
    int getY() {
        return y_;
    }
private:
    int x_;
    int y_;
};

class Temp{
public:
    Temp() : x_(0) {
        cout << "Default ctor" << endl;
    }
    explicit Temp(int x) : x_(x) {
        cout << "ctor with argument" << endl;
    }
    Temp operator + (const Temp &other) {
        return Temp(x_ + other.x_);
    }
    Temp operator + (const int &other) {
        return Temp(x_ + other);
    }
    friend Temp operator + (const int &left, const Temp &right);
    friend ostream & operator << (ostream &os, const Temp &other);

    int getX() {
        return x_;
    }
private:
    int x_;
};

Temp operator + (const int &left, const Temp &right) {
    return Temp(left + right.x_);
}

ostream &operator<<(ostream &os, const Temp &other) {
    os << "Temp(" << other.x_ << ")";
    return os;
}

int main() {
    Temp t1(23);
    Temp t2(24);
    Temp t3 = t1 + 44;
    Temp t4 = 44 + t2;
    cout << t3.getX() << endl;
    cout << t4.getX() << endl;
    cout << "Value: " << t4 << endl;
    return 0;
}
