cmake_minimum_required(VERSION 3.10)
project(PDP_Q3_2020)

set(CMAKE_CXX_STANDARD 17)

set(sources
        ${PROJECT_SOURCE_DIR}/src/linked_list/linked_list.tpp
        ${PROJECT_SOURCE_DIR}/src/hash_table/hash_table_OA.tpp
        ${PROJECT_SOURCE_DIR}/src/hash_table/hash_table.tpp
        ${PROJECT_SOURCE_DIR}/src/my_vector/my_vector.tpp
        ${PROJECT_SOURCE_DIR}/src/b_tree/r_b_tree.tpp
    )

set(tests
        ${PROJECT_SOURCE_DIR}/test/src/my_vector_test.cpp
        ${PROJECT_SOURCE_DIR}/test/src/linked_list_test.cpp
        ${PROJECT_SOURCE_DIR}/test/src/hash_table_test.cpp
        ${PROJECT_SOURCE_DIR}/test/src/hash_table_test_AO.cpp
        ${PROJECT_SOURCE_DIR}/test/src/r_b_tree_test.cpp
        test/src/main.cpp)


add_executable(PDP_Q3_2020 ${sources} ${tests})
