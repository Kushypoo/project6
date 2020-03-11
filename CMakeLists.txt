cmake_minimum_required(VERSION 2.8.9)

project(project6)

include_directories(include/Car_Header include/Vehicle_Header)

set(CAR_SOURCE source/Car_Source/Car.cpp)
add_library(Car_Header ${CAR_SOURCE})

set(VEHICLE_SOURCE source/Vehicle_Source/Vehicle.cpp)
add_library(Vehicle_Header ${VEHICLE_SOURCE})

add_executable(project6 source/main.cpp)

target_link_libraries(project6 Car_Header Vehicle_Header)

install(TARGETS project6 Car_Header Vehicle_Header
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PORJECT_SOURCE_DIR}/devel/lib/static)
	
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
