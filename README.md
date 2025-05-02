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

Задание 1: Создание CMakeLists.txt для библиотеки formatter
```sh
cd formatter_lib

cat > CMakeLists.txt <<EOF
cmake_minimum_required(VERSION 3.4)
project(formatter)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(formatter STATIC \${CMAKE_CURRENT_SOURCE_DIR}/formatter.cpp)

include_directories(\${CMAKE_CURRENT_SOURCE_DIR})
EOF
```

