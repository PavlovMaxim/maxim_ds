# Создание исполняемого файла для бинарного дерева
add_executable(binary_tree_main
    binary_tree_main.cpp
    binary_tree.cpp
    binary_tree.h
)

# Указываем include-путь для заголовков
target_include_directories(binary_tree_main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
