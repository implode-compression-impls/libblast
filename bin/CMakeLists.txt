file(GLOB_RECURSE SRCFILES "${CMAKE_CURRENT_SOURCE_DIR}/*.c" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(blast "${SRCFILES}")
target_include_directories(blast PUBLIC "${Include_dir}")
target_link_libraries(blast PRIVATE libblast)
harden(blast)

cpack_add_component(blast
	DISPLAY_NAME "binary"
	DESCRIPTION "The decompressor binary for PKWare Data Compression Library (DCL) format"
	DEPENDS "library" "library_sdk"
)

install(TARGETS "blast"
	RUNTIME
	COMPONENT "blast"
)

set("CPACK_DEBIAN_BLAST_PACKAGE_NAME" "blast")
set("CPACK_RPM_BLAST_PACKAGE_NAME" "blast")

set("CPACK_DEBIAN_BLAST_PACKAGE_DEPENDS" "${CPACK_DEBIAN_LIBBLAST_PACKAGE_NAME}")
set("CPACK_RPM_BLAST_PACKAGE_DEPENDS" "${CPACK_RPM_LIBBLAST_PACKAGE_NAME}")


list(APPEND CPACK_COMPONENTS_ALL "blast")  # strangely, not populated automatically correctly

pass_through_cpack_vars()
