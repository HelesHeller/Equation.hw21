#include <iostream>
#include <cmath>
#include<windows.h>

class Equation {
public:
    virtual void solve() = 0;
};

class LinearEquation : public Equation {
private:
    double a, b;

public:
    LinearEquation(double coefA, double coefB) : a(coefA), b(coefB) {}

    void solve() override {
        if (a == 0) {
            if (b == 0) {
                std::cout << "Рівняння має безліч розв'язків\n";
            }
            else {
                std::cout << "Рівняння не має розв'язків\n";
            }
        }
        else {
            double x = -b / a;
            std::cout << "Розв'язок рівняння: x = " << x << "\n";
        }
    }
};

class QuadraticEquation : public Equation {
private:
    double a, b, c;

public:
    QuadraticEquation(double coefA, double coefB, double coefC) : a(coefA), b(coefB), c(coefC) {}

    void solve() override {
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            double x1 = (-b + std::sqrt(discriminant)) / (2 * a);
            double x2 = (-b - std::sqrt(discriminant)) / (2 * a);
            std::cout << "Розв'язки рівняння: x1 = " << x1 << ", x2 = " << x2 << "\n";
        }
        else if (discriminant == 0) {
            double x = -b / (2 * a);
            std::cout << "Рівняння має один розв'язок: x = " << x << "\n";
        }
        else {
            std::cout << "Рівняння не має розв'язків у дійсних числах\n";
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Equation* equation1 = new LinearEquation(2, -3);
    equation1->solve();

    Equation* equation2 = new QuadraticEquation(1, -5, 6);
    equation2->solve();

    delete equation1;
    delete equation2;

    return 0;
}
