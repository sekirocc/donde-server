cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)



# use llvm clang, not the apple clang
# set(CMAKE_C_COMPILER    /opt/homebrew/opt/llvm@14/bin/clang)
# set(CMAKE_CXX_COMPILER  /opt/homebrew/opt/llvm@14/bin/clang++ )

project(FaceRecognitionServer LANGUAGES CXX)


include(../cmake/CPM_0.35.1.cmake)

# ------ Donde library ----------
CPMAddPackage(NAME FeatureLibraries SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)


if (NOT DEFINED CONAN_ALREADY_SETUP)
  include(${CMAKE_CURRENT_SOURCE_DIR}/../build/conanbuildinfo.cmake)
  conan_basic_setup(TARGETS)
  include_directories(${CONAN_INCLUDE_DIRS})
  set(CONAN_ALREADY_SETUP true)
endif()

# # ----- openvino library ----
# # install openvino distribution for macos
#
# set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}, "/usr/local/runtime/cmake")
# find_package(OpenVINO REQUIRED COMPONENTS Runtime)


set(CONAN_LIBs
  CONAN_PKG::grpc
  CONAN_PKG::protobuf
  CONAN_PKG::fmt
  CONAN_PKG::opencv
  CONAN_PKG::poco
  CONAN_PKG::msgpack
  CONAN_PKG::sqlitecpp
  CONAN_PKG::spdlog
  CONAN_PKG::nlohmann_json
  CONAN_PKG::cassandra-cpp-driver
  CONAN_PKG::toml11)


######################################################
# ---- Create feature_extract executable ----
######################################################

file(GLOB_RECURSE feature_extract_headers CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/feature_extract/*.h)
file(GLOB_RECURSE feature_extract_sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/feature_extract/*.cc)
add_executable(feature_extract ${feature_extract_headers} ${feature_extract_sources})
target_include_directories(feature_extract
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/feature_extract
  # $<INSTALL_INTERFACE:../include/${PROJECT_NAME}-${PROJECT_VERSION}>
)
target_link_libraries(feature_extract
	${CONAN_LIBs} Donde)


######################################################
# ---- Create feature_search_manager executable ----
######################################################

file(GLOB_RECURSE feature_search_manager_headers CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/feature_search_manager/*.h)
file(GLOB_RECURSE feature_search_manager_sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/feature_search_manager/*.cc)
add_executable(feature_search_manager ${feature_search_manager_headers} ${feature_search_manager_sources})
target_include_directories(feature_search_manager
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/feature_search_manager
  # $<INSTALL_INTERFACE:../include/${PROJECT_NAME}-${PROJECT_VERSION}>
)

target_link_libraries(feature_search_manager
	${CONAN_LIBs} Donde)

######################################################
# ---- Create feature_search_worker executable ----
######################################################

file(GLOB_RECURSE feature_search_worker_headers CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/feature_search_worker/*.h)
file(GLOB_RECURSE feature_search_worker_sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/feature_search_worker/*.cc)
add_executable(feature_search_worker ${feature_search_worker_headers} ${feature_search_worker_sources})
target_include_directories(feature_search_worker
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/feature_search_worker
         # $<INSTALL_INTERFACE:../include/${PROJECT_NAME}-${PROJECT_VERSION}>
)
target_link_libraries(feature_search_worker
	${CONAN_LIBs} Donde)
