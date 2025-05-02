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

