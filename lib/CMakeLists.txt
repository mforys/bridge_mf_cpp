add_library (bridge_mf SHARED src/bridge_util.cpp src/Card.cpp src/Deal.cpp src/Hand.cpp)

target_include_directories (bridge_mf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
