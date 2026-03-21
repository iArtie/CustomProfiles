# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/delivel/CustomProfiles/build-win/_deps/nontype_functional-src")
  file(MAKE_DIRECTORY "/home/delivel/CustomProfiles/build-win/_deps/nontype_functional-src")
endif()
file(MAKE_DIRECTORY
  "/home/delivel/CustomProfiles/build-win/_deps/nontype_functional-build"
  "/home/delivel/CustomProfiles/build-win/_deps/nontype_functional-subbuild/nontype_functional-populate-prefix"
  "/home/delivel/CustomProfiles/build-win/_deps/nontype_functional-subbuild/nontype_functional-populate-prefix/tmp"
  "/home/delivel/CustomProfiles/build-win/_deps/nontype_functional-subbuild/nontype_functional-populate-prefix/src/nontype_functional-populate-stamp"
  "/home/delivel/CustomProfiles/build-win/_deps/nontype_functional-subbuild/nontype_functional-populate-prefix/src"
  "/home/delivel/CustomProfiles/build-win/_deps/nontype_functional-subbuild/nontype_functional-populate-prefix/src/nontype_functional-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/delivel/CustomProfiles/build-win/_deps/nontype_functional-subbuild/nontype_functional-populate-prefix/src/nontype_functional-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/delivel/CustomProfiles/build-win/_deps/nontype_functional-subbuild/nontype_functional-populate-prefix/src/nontype_functional-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
