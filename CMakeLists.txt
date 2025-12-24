cmake_minimum_required(VERSION 3.21)

project(WySDL3_Minimal LANGUAGES C CXX)

# --------------------------------------------------
# Language standards
# --------------------------------------------------
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --------------------------------------------------
# SDL3 paths (adjust if needed)
# --------------------------------------------------
set(SDL3_ROOT "C:/devSDK/SDL3-3.2.6/i686-w64-mingw32")

set(SDL3_INCLUDE_DIR "${SDL3_ROOT}/include/")
set(SDL3_LIBRARY "${SDL3_ROOT}/lib/libSDL3.dll.a")

# --------------------------------------------------
# Executable
# --------------------------------------------------
add_executable(${PROJECT_NAME}
    main.cpp
    src/wyrotatedsquare.cpp
    icon.rc
)

# --------------------------------------------------
# Include directories
# --------------------------------------------------
target_include_directories(${PROJECT_NAME}
    PRIVATE
        include
        ${SDL3_INCLUDE_DIR}
)

# --------------------------------------------------
# Link libraries
# --------------------------------------------------
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${SDL3_LIBRARY}
        mingw32
        user32
        gdi32
        winmm
        dxguid
        opengl32
)

# --------------------------------------------------
# Compiler warnings (ALL configurations)
# --------------------------------------------------
target_compile_options(${PROJECT_NAME}
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wfatal-errors
)

# --------------------------------------------------
# Debug-only flags
# --------------------------------------------------
target_compile_options(${PROJECT_NAME}
    PRIVATE
        $<$<CONFIG:Debug>:-g>
        $<$<CONFIG:Debug>:-O0>
        $<$<CONFIG:Debug>:-DDEBUG>
)

# --------------------------------------------------
# Release-only flags
# --------------------------------------------------
target_compile_options(${PROJECT_NAME}
    PRIVATE
        $<$<CONFIG:Release>:-O2>
        $<$<CONFIG:Release>:-DNDEBUG>
)

# --------------------------------------------------
# MinGW-specific extras
# --------------------------------------------------
if (MINGW)
    target_compile_options(${PROJECT_NAME}
        PRIVATE
            -Wfatal-errors
    )

    # Release linker optimization
    target_link_options(${PROJECT_NAME}
        PRIVATE
            $<$<CONFIG:Release>:-s>
    )
endif()

# --------------------------------------------------
# Output directories (optional, matches Code::Blocks)
# --------------------------------------------------
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_BINARY_DIR}/bin/Debug
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/Release
)
