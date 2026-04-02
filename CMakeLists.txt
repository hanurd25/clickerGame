cmake_minimum_required(VERSION 3.29)
project(CakeClicker)

set(CMAKE_CXX_STANDARD 20)

add_executable(CakeClicker src/main.cpp src/GameLogic.cpp)

target_link_options(CakeClicker PRIVATE
        "SHELL: -s WASM=1"
        "SHELL: -s MODULARIZE=1"
        "SHELL: -s EXPORT_NAME='CakeClickerModule'"
        "SHELL: -s EXPORTED_RUNTIME_METHODS=['ccall','cwrap']"
        "SHELL: -s EXPORT_ES6=1"
        "--bind"
)
# Only keep this if the 'web' folder actually exists with files in it!
# file(COPY web/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/web)