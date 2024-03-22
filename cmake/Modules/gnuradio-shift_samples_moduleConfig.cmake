find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_SHIFT_SAMPLES_MODULE gnuradio-shift_samples_module)

FIND_PATH(
    GR_SHIFT_SAMPLES_MODULE_INCLUDE_DIRS
    NAMES gnuradio/shift_samples_module/api.h
    HINTS $ENV{SHIFT_SAMPLES_MODULE_DIR}/include
        ${PC_SHIFT_SAMPLES_MODULE_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_SHIFT_SAMPLES_MODULE_LIBRARIES
    NAMES gnuradio-shift_samples_module
    HINTS $ENV{SHIFT_SAMPLES_MODULE_DIR}/lib
        ${PC_SHIFT_SAMPLES_MODULE_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-shift_samples_moduleTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_SHIFT_SAMPLES_MODULE DEFAULT_MSG GR_SHIFT_SAMPLES_MODULE_LIBRARIES GR_SHIFT_SAMPLES_MODULE_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_SHIFT_SAMPLES_MODULE_LIBRARIES GR_SHIFT_SAMPLES_MODULE_INCLUDE_DIRS)
