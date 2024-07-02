cmake_minimum_required(VERSION 3.5)
project(DataStructures LANGUAGES CXX)
set (EXE_NAME Data_Structures_Test)

##########################################
# Edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....

#set (input01 "")
#set (input02 "")
#set (input03 "")
#set (input04 "")

#
##########################################

# Copy data files to build dir
#foreach(file IN LISTS input01 input02 input03 input04)
#    configure_file(${file} ${file} COPYONLY)
#endforeach()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${EXE_NAME} ./main.cpp
	DSString/dsstring.h DSString/dsstring.cpp 
	./catch.hpp
        ./test.cpp
        DSVector/dsvector.h
        DSStack/dsstack.h
        DSDoublyLL/dsnode.h
        DSDoublyLL/dsdoublyll.h)
