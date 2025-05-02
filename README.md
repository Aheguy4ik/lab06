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
cmake --build .
```

