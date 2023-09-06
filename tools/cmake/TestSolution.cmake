function(add_leetcode_executable NAME)
  set(MULTI_VALUE_ARGS SOLUTION_SRCS)
  cmake_parse_arguments(LEETCODE_LIBRARY "" "" "${MULTI_VALUE_ARGS}" ${ARGN})

  add_executable(${NAME}
    ${LEETCODE_LIBRARY_UNPARSED_ARGUMENTS}
    ${LEETCODE_LIBRARY_SOLUTION_SRCS})

  target_include_directories(${NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
endfunction()

function(add_catch TARGET)
  add_leetcode_executable(${TARGET}
    ${ARGN})

  target_link_libraries(${TARGET}
    contrib_catch_main)

  add_test(NAME ${TARGET} COMMAND ${TARGET})
endfunction()
