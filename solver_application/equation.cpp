#include "formatter_ex.h"
#include "solver.h"
#include <iostream>
#include <cmath>

int main() {
    // Решаем уравнение x² - 5x + 6 = 0
    double a = 1.0, b = -5.0, c = 6.0;
    
    // Находим оба корня
    double root1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
    double root2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
    
    std::string result = "Уравнение: " + std::to_string(a) + "x² + " + 
                        std::to_string(b) + "x + " + 
                        std::to_string(c) + " = 0\n" +
                        "Корни: x₁ = " + std::to_string(root1) + 
                        ", x₂ = " + std::to_string(root2);
    
    // Вывод в файл и консоль
    print_ex(result);
    std::cout << result << std::endl;
    
    return 0;
}
