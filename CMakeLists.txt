cmake_minimum_required(VERSION 3.10)
project(lab03 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем необходимые политики
cmake_policy(SET CMP0002 NEW)
cmake_policy(SET CMP0079 NEW)

# Включаем подпроекты
add_subdirectory(formatter_lib)
add_subdirectory(formatter_ex_lib)
add_subdirectory(solver_lib)
add_subdirectory(hello_world_application)
add_subdirectory(solver_application)

# Устанавливаем бинарник solver
install(TARGETS solver RUNTIME DESTINATION bin)

# Добавим установку системных библиотек, если нужно
include(InstallRequiredSystemLibraries)

# Настройки пакета
set(CPACK_PACKAGE_NAME "lab03")
set(CPACK_PACKAGE_VERSION "0.1.0")
set(CPACK_PACKAGE_CONTACT "you@example.com")

# Базовые генераторы
set(CPACK_GENERATOR "ZIP;TGZ")

# Генератор для Windows
if(WIN32)
    list(APPEND CPACK_GENERATOR "WIX")
    # По желанию: добавь файл LICENSE.rtf, если нужно отобразить лицензию при установке
    # set(CPACK_WIX_LICENSE_RTF "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.rtf")
endif()

# Генератор для macOS
if(APPLE)
    list(APPEND CPACK_GENERATOR "DragNDrop")
endif()

# Подключаем CPack
include(CPack)
