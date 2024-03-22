# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT shift_samples_module_sources)
    MESSAGE(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT shift_samples_module_sources)

########################################################################
# Check for pygccxml
########################################################################
GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND shift_samples_module_python_files
    shift_samples_python.cc python_bindings.cc)

GR_PYBIND_MAKE_OOT(shift_samples_module
   ../../..
   gr::shift_samples_module
   "${shift_samples_module_python_files}")

# copy bindings extension for use in QA test module
add_custom_command(TARGET shift_samples_module_python POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:shift_samples_module_python>
    ${PROJECT_BINARY_DIR}/test_modules/gnuradio/shift_samples_module/
)

install(TARGETS shift_samples_module_python DESTINATION ${GR_PYTHON_DIR}/gnuradio/shift_samples_module COMPONENT pythonapi)
