add_executable(list list.cpp)
target_link_libraries(list xscript-core)

add_executable(dict dict.cpp)
target_link_libraries(dict xscript-core)

add_executable(string string.cpp)
target_link_libraries(string xscript-core)

add_executable(symbol symbol.cpp)
target_link_libraries(symbol xscript-core)
