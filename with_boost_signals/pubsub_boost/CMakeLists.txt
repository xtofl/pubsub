project(pubsub_boost)
add_compile_options(-std=gnu++14)

cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})
find_package(Boost 1.58.0 REQUIRED system)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

