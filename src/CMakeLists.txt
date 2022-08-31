add_executable(${PROJECT_NAME}
    main.cpp
    ./hw/UltraSonic/UltraSonic.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ./
    ./hw
    ./hw/UltraSonic
)

target_compile_options(${PROJECT_NAME} PUBLIC
    -Wall
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    -lwiringPi
)

