#############################################
##### Declaring
#############################################

set(libname  "kornyakov-kirill-scalc3-library")
set(testname "kornyakov-kirill-scalc3-test")
set(appname  "kornyakov-kirill-scalc3-application")

message("")
message("############################################")
message("##### Testing ${libname}")
message("############################################")
message("")

#############################################
##### Building
#############################################

# Declare directory with public headers
add_dir_inc("./")

# Declare static library
add_lib_static(${libname} "include" "src")

# Declare module with unit tests
add_local_dependency(${libname})
add_app(${testname} "test")
target_link_libraries(${testname})

# Declare application
add_local_dependency(${libname})
add_app(${appname} "application")

#############################################
##### Testing
#############################################

include("CTestTests.txt")
