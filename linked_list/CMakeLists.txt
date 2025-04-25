# Создание исполняемого файла для связного списка
add_executable(linked_list_main
    linked_list_main.cpp
    linked_list.cpp
    linked_list.h
)

# Указываем include-путь для заголовков
target_include_directories(linked_list_main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
