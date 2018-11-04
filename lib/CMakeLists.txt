set (CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES
    "inc/*.h"
    "src/*.cpp"
)

#message ( ${SOURCES} )

add_library (bridge_mf SHARED ${SOURCES})

target_include_directories (bridge_mf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
