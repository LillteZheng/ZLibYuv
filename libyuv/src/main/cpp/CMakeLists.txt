# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION  3.18.1)

# Declares and names the project.

project("libyuvdemo")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        ZYuvTools

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp
        )


#add_library(myTest SHARED myTest.cpp)





# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

#yuv
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libyuv/include)
set(libyuv_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libyuv)
file(GLOB libyuv_SRC ${libyuv_DIR}/source/*.cc)
add_library(libyuv SHARED ${libyuv_SRC})


# 要使用 NEON 在 CMake 目标中构建所有源文件，请将以下内容添加到 CMakeLists.txt 中
if(ANDROID_ABI STREQUAL arm64-v8a)
    set_target_properties(xxx PROPERTIES COMPILE_FLAGS -mfpu=neon)
endif()


target_link_libraries( # Specifies the target library.
        ZYuvTools
        libyuv
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})