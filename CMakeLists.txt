cmake_minimum_required(VERSION 3.13)

message(STATUS "We have moved from M$ GitHub to https://codeberg.org/implode-compression-impls/libblast , read why on https://codeberg.org/KOLANICH/Fuck-GuanTEEnomo . ")

set(CMAKE_USE_RELATIVE_PATHS TRUE)
project("blast")
set("PROJECT_DESCRIPTION" "Free open source PKWare Data Compression Library (DCL) implementation")
set("PROJECT_HOMEPAGE_URL" "https://github.com/madler/zlib/tree/master/contrib/blast")
set(CPACK_PACKAGE_VENDOR "Mark Adler")

set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "2")
set(CPACK_PACKAGE_VERSION_PATCH "9")
set(CPACK_PACKAGE_VERSION "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")

set(OUR_CMAKE_MODULES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(OUR_CMAKE_3PARTY_MODULES_DIR "${OUR_CMAKE_MODULES_DIR}/thirdParty")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${OUR_CMAKE_MODULES_DIR}" "${OUR_CMAKE_MODULES_DIR}/Boilerplate" "${OUR_CMAKE_MODULES_DIR}/DoxygenUtils" "${OUR_CMAKE_3PARTY_MODULES_DIR}")

include(Boilerplate)

set(Include_dir "${CMAKE_CURRENT_SOURCE_DIR}/include")
file(GLOB_RECURSE HDRFILES "${Include_dir}/*.h" "${Include_dir}/*.hpp")

set(LibSource_dir "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(BinSource_dir "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(PackagingTemplatesDir "${CMAKE_CURRENT_SOURCE_DIR}/packaging")
set(tests_dir "${CMAKE_CURRENT_SOURCE_DIR}/tests")


set(CPACK_PACKAGE_MAINTAINER "${CPACK_PACKAGE_VENDOR}")
set(CPACK_DEBIAN_PACKAGE_NAME "${CPACK_PACKAGE_NAME}")
set(CPACK_RPM_PACKAGE_NAME "${CPACK_PACKAGE_NAME}")

add_subdirectory("${LibSource_dir}")
add_subdirectory("${BinSource_dir}")

option(WITH_TESTS ON "Enable testing")

if(WITH_TESTS)
	add_subdirectory("${tests_dir}")
	enable_testing()
endif()

set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_RPM_COMPONENT_INSTALL ON)
set(CPACK_NSIS_COMPONENT_INSTALL ON)
#set(CPACK_DEBIAN_ENABLE_COMPONENT_DEPENDS ON)
set(CPACK_RPM_ENABLE_COMPONENT_DEPENDS ON)
set(CPACK_DEBIAN_COMPRESSION_TYPE "xz")

include(CPack)
