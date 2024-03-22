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
    std::memcpy(optr, iptr, noutput_items * d_itemsize);

    return noutput_items;
}

} /* namespace shift_samples_module */
} /* namespace gr */
