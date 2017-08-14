
#
# Copyright (C) The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required(VERSION 3.4.1)

# configure import libs
set(distribution_DIR ${CMAKE_SOURCE_DIR}/../../../../distribution)
#set(AddSwiftDIR ${CMAKE_SOURCE_DIR}/../../../../../AddSwift)
set(ANDROID_LIBS_DIR /Users/aaboelela/android/libs)

add_library(lib_gmath STATIC IMPORTED)
set_target_properties(lib_gmath PROPERTIES IMPORTED_LOCATION
    ${distribution_DIR}/gmath/lib/${ANDROID_ABI}/libgmath.a)

# shared lib will also be tucked into APK and sent to target
# refer to app/build.gradle, jniLibs section for that purpose.
# ${ANDROID_ABI} is handy for our purpose here. Probably this ${ANDROID_ABI} is
# the most valuable thing of this sample, the rest are pretty much normal cmake
add_library(lib_gperf SHARED IMPORTED)
set_target_properties(lib_gperf PROPERTIES IMPORTED_LOCATION
    ${distribution_DIR}/gperf/lib/${ANDROID_ABI}/libgperf.so)

add_library(AddSwift SHARED IMPORTED)
set_target_properties(AddSwift PROPERTIES IMPORTED_LOCATION
    ${ANDROID_LIBS_DIR}/${ANDROID_ABI}/libAddSwift.so)

#add_library(gaddswift SHARED IMPORTED)
#set_target_properties(gaddswift PROPERTIES IMPORTED_LOCATION
#    /Users/aaboelela/android/libs/${ANDROID_ABI}/libgaddswift.so)

#add_library(swiftCore SHARED IMPORTED)
#set_target_properties(swiftCore PROPERTIES IMPORTED_LOCATION
#    /Users/aaboelela/android/libs/${ANDROID_ABI}/libswiftCore.so)

# build application's shared lib
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

add_library(add-swift SHARED
            add-swift.cpp)

target_include_directories(add-swift PRIVATE
                           ${distribution_DIR}/gmath/include
                           ${distribution_DIR}/gperf/include)

target_link_libraries(add-swift
                      android
                      lib_gmath
                      lib_gperf
                      log
                      AddSwift)
