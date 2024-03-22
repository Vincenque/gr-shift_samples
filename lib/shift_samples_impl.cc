#include "shift_samples_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace shift_samples_module {

shift_samples::sptr shift_samples::make(size_t itemsize, int number_of_samples_to_shift = 0)
{
    return gnuradio::make_block_sptr<shift_samples_impl>(itemsize, number_of_samples_to_shift);
}

shift_samples_impl::shift_samples_impl(size_t itemsize, int number_of_samples_to_shift = 0)
    : gr::sync_block("shift_samples",
                     gr::io_signature::make(
                         1 /* min inputs */, 1 /* max inputs */, itemsize),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, itemsize)),
      d_itemsize(itemsize),
      d_number_of_samples_to_shift(number_of_samples_to_shift)
{
}

shift_samples_impl::~shift_samples_impl() {}

int shift_samples_impl::work(int noutput_items,
                             gr_vector_const_void_star& input_items,
                             gr_vector_void_star& output_items)
{
    const char* iptr;
    char* optr;
    iptr = (const char*)input_items[0];
    optr = (char*)output_items[0];

    // Calculate the absolute shift value with modulo operation
    int shift_value = std::abs(d_number_of_samples_to_shift) % noutput_items;

    // Create a temporary buffer to hold the data
    char* temp_buffer = new char[noutput_items * d_itemsize];

    // Copy the input data to the temporary buffer
    std::memcpy(temp_buffer, iptr, noutput_items * d_itemsize);

    if (d_number_of_samples_to_shift > 0) {
        // Right shift
        // Copy the shifted samples to the output
        std::memcpy(optr, temp_buffer + shift_value * d_itemsize, (noutput_items - shift_value) * d_itemsize);
        // Move the remaining samples to the front
        std::memcpy(optr + (noutput_items - shift_value) * d_itemsize, temp_buffer, shift_value * d_itemsize);
    } else {
        // Left shift
        // Copy the shifted samples to the output
        std::memcpy(optr, temp_buffer + (noutput_items - shift_value) * d_itemsize, shift_value * d_itemsize);
        // Move the remaining samples to the end
        std::memcpy(optr + shift_value * d_itemsize, temp_buffer, (noutput_items - shift_value) * d_itemsize);
    }

    // Delete the temporary buffer
    delete[] temp_buffer;

    return noutput_items;
}

} /* namespace shift_samples_module */
} /* namespace gr */
