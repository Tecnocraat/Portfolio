cmake_minimum_required(VERSION 3.16)

project(Currencyconverterv3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Locate Qt Framework
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# 2. Configure vcpkg paths
set(VCPKG_ROOT "C:/Users/Administrador/vcpkg/installed/x64-windows")
set(VCPKG_INCLUDE_DIRS "${VCPKG_ROOT}/include")
set(VCPKG_LIBS "${VCPKG_ROOT}/lib")

# 3. Configure PostgreSQL paths
set(PG_PATH "C:/Program Files/PostgreSQL/18")
set(PostgreSQL_INCLUDE_DIRS "${PG_PATH}/include")
set(PostgreSQL_LIBRARIES "${PG_PATH}/lib/libpq.lib")

# 4. Include search directories
include_directories(${PostgreSQL_INCLUDE_DIRS})
include_directories(${VCPKG_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
# Include src directory to resolve moved header paths natively
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# 5. List project source files
set(PROJECT_SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    src/mainwindow.ui
    src/CurrencyAPI.cpp
    src/CurrencyAPI.h
    src/DatabaseManager.cpp
    src/DatabaseManager.h
    src/EnvLoader.cpp
    src/EnvLoader.h
    src/ExchangeCache.h
    resources/resources.rc
)

# 6. Create the Target Executable
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Currencyconverterv3
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(Currencyconverterv3 ${PROJECT_SOURCES})
endif()

# 7. Link Target Libraries (Using direct references)
target_link_libraries(Currencyconverterv3
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    "${PG_PATH}/lib/libpq.lib"
    "${VCPKG_LIBS}/libcurl.lib"
    "${VCPKG_LIBS}/pqxx.lib"
)

# Extra target configurations
set_target_properties(Currencyconverterv3 PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Currencyconverterv3)
endif()
