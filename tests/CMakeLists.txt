
find_package(GTest)
find_package(fileTestSuite_runner)

add_library(tests SHARED "${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp")
message(STATUS "pkgcfg_lib_fileTestSuite_runner_FileTestSuite_runner ${pkgcfg_include_fileTestSuite_runner_FileTestSuite_runner}")
target_compile_definitions(tests PRIVATE "-DLIBFILETESTSUITE_BACKEND_EXPORTS")

target_include_directories(tests PRIVATE "${pkgcfg_include_fileTestSuite_runner_FileTestSuite_runner}")
set_property(TARGET tests PROPERTY CXX_STANDARD 20)
message(STATUS "pkgcfg_lib_fileTestSuite_runner_FileTestSuite_runner ${pkgcfg_lib_fileTestSuite_runner_FileTestSuite_runner}")
target_link_libraries(tests PRIVATE libblast GTest::gtest "${pkgcfg_lib_fileTestSuite_runner_FileTestSuite_runner}")
#gtest_discover_tests(tests)
