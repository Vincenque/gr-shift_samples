/*
 * Copyright 2024 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(shift_samples.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(1ce0201ffe5dd5a2800943012e209c3d)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/shift_samples_module/shift_samples.h>
// pydoc.h is automatically generated in the build directory
#include <shift_samples_pydoc.h>

void bind_shift_samples(py::module& m)
{

    using shift_samples    = gr::shift_samples_module::shift_samples;


    py::class_<shift_samples, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<shift_samples>>(m, "shift_samples", D(shift_samples))

        .def(py::init(&shift_samples::make),
           D(shift_samples,make)
        )
        



        ;




}







