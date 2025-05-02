##Homework III

0. Подготовка репозитория:
```sh 
git clone https://github.com/<username>/lab03.git
cd lab03
```
Создаем структуру папок для проекта:
```sh
mkdir -p formatter_lib formatter_ex_lib solver_lib hello_world solver
```

Задание 1:
```sh
cd formatter_lib

#Создаем CMakeLists.txt для библиотеки formatter:
cat > CMakeLists.txt <<'EOF'
cmake_minimum_required(VERSION 3.10)
project(formatter LANGUAGES CXX)

add_library(formatter STATIC formatter.cpp)
target_include_directories(formatter PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
EOF

#Создаем исходные файлы библиотеки:
cat > formatter.cpp <<'EOF'
#include "formatter.h"
#include <iostream>

void print(const std::string& text) {
    std::cout << text << std::endl;
}
EOF

cat > formatter.h <<'EOF'
#pragma once
#include <string>

void print(const std::string& text);
EOF

#Собираем библиотеку:
mkdir build
cd build
cmake ..
cd ../..
#Вывод:
[aheguy@aheguy-nitroan51554 build]$ cmake ..
-- The CXX compiler identification is GNU 14.2.1
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.4s)
-- Generating done (0.0s)
-- Build files have been written to: /home/aheguy/Aheguy4ik/workspace/projects/lab03/formatter_lib/build

cmake --build .
#Вывод:
[aheguy@aheguy-nitroan51554 build]$ cmake --build .
[ 50%] Building CXX object CMakeFiles/formatter.dir/formatter.cpp.o
[100%] Linking CXX static library libformatter.a
[100%] Built target formatter

```
Задание 2:

```sh
cd ../..
cd formatter_ex_lib

#Создаем CMakeLists.txt для formatter_ex:
cat > CMakeLists.txt <<'EOF'
cmake_minimum_required(VERSION 3.10)
project(formatter_ex LANGUAGES CXX)

# Используем ../formatter_lib для относительного пути
add_subdirectory(../formatter_lib ${CMAKE_CURRENT_BINARY_DIR}/formatter)

add_library(formatter_ex STATIC formatter_ex.cpp)
target_include_directories(formatter_ex PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib
)
target_link_libraries(formatter_ex PUBLIC formatter)
EOF

#Создаем исходные файлы библиотеки formatter_ex:
cat > formatter_ex.cpp <<'EOF'
#include "formatter_ex.h"
#include <fstream>

void print_ex(const std::string& text) {
    std::ofstream out("log.txt");
    out << text;
    out.close();
}
EOF

cat > formatter_ex.h <<'EOF'
#pragma once
#include <string>

void print_ex(const std::string& text);
EOF

#Собираем библиотеку:
mkdir build && cd build
cmake .. && cmake --build .
cd ../..
#Вывод:
[aheguy@aheguy-nitroan51554 build]$ cmake .. && cmake --build .
-- The CXX compiler identification is GNU 14.2.1
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.2s)
-- Generating done (0.0s)
-- Build files have been written to: /home/aheguy/Aheguy4ik/workspace/projects/lab03/formatter_ex_lib/build
[ 25%] Building CXX object formatter/CMakeFiles/formatter.dir/formatter.cpp.o
[ 50%] Linking CXX static library libformatter.a
[ 50%] Built target formatter
[ 75%] Building CXX object CMakeFiles/formatter_ex.dir/formatter_ex.cpp.o
[100%] Linking CXX static library libformatter_ex.a
[100%] Built target formatter_ex
```
Задание 3:
```sh
cd hello_world_application

# Создаем CMakeLists.txt
cat > CMakeLists.txt <<'EOF'
cmake_minimum_required(VERSION 3.10)
project(hello_world LANGUAGES CXX)

# Используем явный относительный путь
add_subdirectory(../formatter_ex_lib ${CMAKE_CURRENT_BINARY_DIR}/formatter_ex)

add_executable(hello_world hello_world.cpp)
target_include_directories(hello_world PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_ex_lib
)
target_link_libraries(hello_world PRIVATE formatter_ex)
EOF

# Создаем исходный файл
cat > hello_world.cpp <<'EOF'
#include "formatter_ex.h"

int main() {
    print_ex("Hello, World!");
    return 0;
}
EOF

# Собираем приложение
mkdir build && cd build
cmake .. && cmake --build .
cd ../..
#Вывод:
[aheguy@aheguy-nitroan51554 build]$ cmake .. && cmake --build .
-- The CXX compiler identification is GNU 14.2.1
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.2s)
-- Generating done (0.0s)
-- Build files have been written to: /home/aheguy/Aheguy4ik/workspace/projects/lab03/hello_world_application/build
[ 16%] Building CXX object formatter_ex/formatter/CMakeFiles/formatter.dir/formatter.cpp.o
[ 33%] Linking CXX static library libformatter.a
[ 33%] Built target formatter
[ 50%] Building CXX object formatter_ex/CMakeFiles/formatter_ex.dir/formatter_ex.cpp.o
[ 66%] Linking CXX static library libformatter_ex.a
[ 66%] Built target formatter_ex
[ 83%] Building CXX object CMakeFiles/hello_world.dir/hello_world.cpp.o
[100%] Linking CXX executable hello_world
[100%] Built target hello_world
```
Приложение solver:
```sh
# Сначала создаем solver_lib
cd solver_lib

# CMakeLists.txt для solver_lib
cat > CMakeLists.txt <<'EOF'
cmake_minimum_required(VERSION 3.10)
project(solver_lib LANGUAGES CXX)

add_library(solver_lib STATIC solver.cpp)
target_include_directories(solver_lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
EOF

# Исходные файлы solver_lib
cat > solver.h <<'EOF'
#pragma once

double solve(double a, double b, double c);
EOF

cat > solver.cpp <<'EOF'
#include "solver.h"
#include <cmath>

double solve(double a, double b, double c) {
    return (-b + sqrt(b*b - 4*a*c)) / (2*a);
}
EOF

# Собираем библиотеку
mkdir build && cd build
cmake .. && cmake --build .
cd ../..
#Вывод:
[aheguy@aheguy-nitroan51554 build]$ cmake .. && cmake --build .
-- The CXX compiler identification is GNU 14.2.1
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.2s)
-- Generating done (0.0s)
-- Build files have been written to: /home/aheguy/Aheguy4ik/workspace/projects/lab03/solver_lib/build
[ 50%] Building CXX object CMakeFiles/solver_lib.dir/solver.cpp.o
[100%] Linking CXX static library libsolver_lib.a
[100%] Built target solver_lib


# Теперь создаем solver приложение
cd solver_application

# CMakeLists.txt для solver
cat > CMakeLists.txt <<'EOF'
cmake_minimum_required(VERSION 3.10)
project(solver_app)

# Простые относительные пути с явным указанием бинарной директории
add_subdirectory(../formatter_ex_lib formatter_ex_build)
add_subdirectory(../solver_lib solver_build)

add_executable(solver equation.cpp)
target_link_libraries(solver formatter_ex solver_lib)
EOF


# Исходный файл приложения
cat > equation.cpp <<'EOF'
#include "formatter_ex.h"
#include "solver.h"
#include <iostream>

int main() {
    double a = 1.0, b = -3.0, c = 2.0;
    double root = solve(a, b, c);
    
    std::string result = "Root: " + std::to_string(root);
    print_ex(result);
    
    std::cout << result << std::endl;
    return 0;
}
EOF

# Собираем приложение
mkdir build && cd build
cmake .. && cmake --build .
cd ../..
#Вывод:
[aheguy@aheguy-nitroan51554 build]$ cmake .. && cmake --build .
-- The C compiler identification is GNU 14.2.1
-- The CXX compiler identification is GNU 14.2.1
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.4s)
-- Generating done (0.0s)
-- Build files have been written to: /home/aheguy/Aheguy4ik/workspace/projects/lab03/solver_application/build
[ 12%] Building CXX object solver_build/CMakeFiles/solver_lib.dir/solver.cpp.o
[ 25%] Linking CXX static library libsolver_lib.a
[ 25%] Built target solver_lib
[ 37%] Building CXX object formatter_ex_build/formatter/CMakeFiles/formatter.dir/formatter.cpp.o
[ 50%] Linking CXX static library libformatter.a
[ 50%] Built target formatter
[ 62%] Building CXX object formatter_ex_build/CMakeFiles/formatter_ex.dir/formatter_ex.cpp.o
[ 75%] Linking CXX static library libformatter_ex.a
[ 75%] Built target formatter_ex
[ 87%] Building CXX object CMakeFiles/solver.dir/equation.cpp.o
[100%] Linking CXX executable solver
[100%] Built target solver
```












































