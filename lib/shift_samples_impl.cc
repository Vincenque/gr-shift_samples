// shift_samples_impl.cc
#include "shift_samples_impl.h"
#include <gnuradio/io_signature.h>
#include <vector>

namespace gr {
namespace shift_samples_module {

shift_samples::sptr shift_samples::make(size_t type_size,
                                        int vector_length,
                                        int number_of_samples_to_shift = 0)
{
    return gnuradio::make_block_sptr<shift_samples_impl>(
        type_size, vector_length, number_of_samples_to_shift);
}

shift_samples_impl::shift_samples_impl(size_t type_size,
                                       int vector_length,
                                       int number_of_samples_to_shift = 0)
    : gr::sync_block(
          "shift_samples",
          gr::io_signature::make(
              1 /* min inputs */, 1 /* max inputs */, type_size * vector_length),
          gr::io_signature::make(
              1 /* min outputs */, 1 /*max outputs */, type_size * vector_length)),
      d_type_size(type_size),
      d_number_of_samples_to_shift(number_of_samples_to_shift),
      d_vector_length(vector_length)
{
}

shift_samples_impl::~shift_samples_impl() {}

int shift_samples_impl::work(int noutput_items,
                             gr_vector_const_void_star& input_items,
                             gr_vector_void_star& output_items)
{
    const char* in = (const char*)input_items[0];
    char* out = (char*)output_items[0];

    int effective_shift_samples = d_number_of_samples_to_shift % d_vector_length;
    if (effective_shift_samples < 0) {
        effective_shift_samples = effective_shift_samples + d_vector_length;
    }
    int shift_bytes = effective_shift_samples * d_type_size;

    // If the shift is zero, simply copy the input vector to the output vector
    if (d_number_of_samples_to_shift == 0) {
        std::memcpy(out, in, noutput_items * d_type_size * d_vector_length);
    } else {
        // Shift the samples in the buffer
        std::memmove(out,
                     in + shift_bytes,
                     (noutput_items * d_type_size * d_vector_length) - shift_bytes);

        // Copy the remaining samples from the end of the input buffer to the beginning of
        // the output buffer
        std::memcpy(out + ((noutput_items * d_type_size * d_vector_length) - shift_bytes),
                    in,
                    shift_bytes);
    }

    // Tell runtime system how many output items we produced.
    return noutput_items;
}


} /* namespace shift_samples_module */
} /* namespace gr */
