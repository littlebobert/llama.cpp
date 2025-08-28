add_library(mimi-model STATIC mimi-model.h mimi-model.cpp)
target_link_libraries(mimi-model PRIVATE llama common ${CMAKE_THREAD_LIBS_INIT})
# for using C++ designated initializers, TODO: can be changed back to C++17 in the future
target_compile_features(mimi-model PRIVATE cxx_std_20)

# Create a library for Swift integration
set(LIB_TARGET llama-tts-csm-lib)
add_library(${LIB_TARGET} STATIC
    tts-csm.cpp
)

# Add include directories
target_include_directories(${LIB_TARGET} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../
    ${CMAKE_CURRENT_SOURCE_DIR}/../../ggml/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/
    ${CMAKE_CURRENT_SOURCE_DIR}/../../common/
)
#
# set_target_properties(${LIB_TARGET}
#     PROPERTIES
#         PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/include/tts.h"
#         FRAMEWORK TRUE
#         FRAMEWORK_VERSION A
#         MACOSX_FRAMEWORK_IDENTIFIER "com.llama.tts"
#         MACOSX_FRAMEWORK_BUNDLE_VERSION "1.0"
#         MACOSX_FRAMEWORK_SHORT_VERSION_STRING "1.0"
#         # Set the bundle identifier explicitly for Xcode
#         XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER "com.llama.tts"
# )
target_link_libraries(${LIB_TARGET} PRIVATE common mimi-model ${CMAKE_THREAD_LIBS_INIT})

# Install the library
install(TARGETS ${LIB_TARGET}
    LIBRARY DESTINATION lib
    FRAMEWORK DESTINATION Frameworks
    PUBLIC_HEADER DESTINATION include/llama-tts)
