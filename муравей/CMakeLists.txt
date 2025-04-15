cmake_minimum_required(VERSION 3.10)
project(AntSimulation)

set(CMAKE_CXX_STANDARD 17)

# Указываем путь к SFML
set(SFML_DIR "/opt/homebrew/Cellar/sfml/3.0.0_1/lib/cmake/SFML")

# Ищем пакеты SFML
find_package(SFML REQUIRED COMPONENTS Graphics Window System)

# Подключаем директории с хедерами
include_directories(include)

# Создаём исполняемый файл
add_executable(AntSimulation
    src/main.cpp
    src/ant.cpp
    src/anthill.cpp
    src/roles.cpp
    src/enemy.cpp
    src/notifier.cpp
    src/food.cpp
    src/sticks.cpp
)


# Линкуем с новыми targets
target_link_libraries(AntSimulation
    SFML::Graphics
    SFML::Window
    SFML::System
)
add_custom_command(TARGET AntSimulation POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:AntSimulation>/assets
)