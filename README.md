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













































