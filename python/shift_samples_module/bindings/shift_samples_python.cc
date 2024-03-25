#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/shift_samples_module/shift_samples.h>

#include <shift_samples_pydoc.h>

void bind_shift_samples(py::module& m)
{
    using shift_samples = gr::shift_samples_module::shift_samples;
    py::class_<shift_samples,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<shift_samples>>(m, "shift_samples", D(shift_samples))
        .def(py::init(&shift_samples::make),
             py::arg("type_size"),
             py::arg("vector_length"),
             py::arg("number_of_samples_to_shift"),
             D(shift_samples, make))
        .def("set_number_of_samples_to_shift",
             &shift_samples::set_number_of_samples_to_shift,
             py::arg("number_of_samples_to_shift"),
             D(shift_samples, set_number_of_samples_to_shift))
        .def("number_of_samples_to_shift",
             &shift_samples::number_of_samples_to_shift,
             D(shift_samples, number_of_samples_to_shift));
}
