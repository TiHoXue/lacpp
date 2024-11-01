add_library(lacpplib STATIC la_vector.cpp)

target_include_directories(lacpplib PUBLIC ${PROJECT_SOURCE_DIR}/include)