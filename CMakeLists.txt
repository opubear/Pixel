cmake_minimum_required(VERSION 3.23.0)

project(Pixel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

file(GLOB_RECURSE CPP_FILES CONFIGURE_DEPENDS Source/*.cpp)
file(GLOB_RECURSE H_FILES CONFIGURE_DEPENDS Source/*.h)
set(ALL_FILES ${CPP_FILES} ${H_FILES})

# Automatically create source_group directives for the sources passed in.
function(auto_source_group rootName rootDir)
  file(TO_CMAKE_PATH "${rootDir}" rootDir)
  string(LENGTH "${rootDir}" rootDirLength)
  set(sourceGroups)
  foreach (fil ${ARGN})
    file(TO_CMAKE_PATH "${fil}" filePath)
    string(FIND "${filePath}" "/" rIdx REVERSE)
    if (rIdx EQUAL -1)
      message(FATAL_ERROR "Unable to locate the final forward slash in '${filePath}'!")
    endif()
    string(SUBSTRING "${filePath}" 0 ${rIdx} filePath)

    string(LENGTH "${filePath}" filePathLength)
    string(FIND "${filePath}" "${rootDir}" rIdx)
    if (rIdx EQUAL 0)
      math(EXPR filePathLength "${filePathLength} - ${rootDirLength}")
      string(SUBSTRING "${filePath}" ${rootDirLength} ${filePathLength} fileGroup)

      string(REPLACE "/" "\\" fileGroup "${fileGroup}")
      set(fileGroup "\\${rootName}${fileGroup}")

      list(FIND sourceGroups "${fileGroup}" rIdx)
      if (rIdx EQUAL -1)
        list(APPEND sourceGroups "${fileGroup}")
        # message(STATUS "Adding source group: ${fileGroup}")
        source_group("${fileGroup}" REGULAR_EXPRESSION "${filePath}/[^/.]+.(cpp|h|c)$")
      endif()
    endif()
  endforeach()
endfunction()

auto_source_group(Source ${CMAKE_CURRENT_SOURCE_DIR}/Source ${ALL_FILES})

add_executable(Pixel ${ALL_FILES})
target_include_directories(Pixel PUBLIC Source)

# Add third party libraries
add_subdirectory(ThirdParty)

target_link_libraries(${PROJECT_NAME} PUBLIC
    glfw
    volk
    glm
    stb
    tinyobjloader
)
