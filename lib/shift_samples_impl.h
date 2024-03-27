// shift_samples_impl.h
#ifndef INCLUDED_SHIFT_SAMPLES_MODULE_SHIFT_SAMPLES_IMPL_H
#define INCLUDED_SHIFT_SAMPLES_MODULE_SHIFT_SAMPLES_IMPL_H

#include <gnuradio/shift_samples_module/shift_samples.h>

namespace gr {
namespace shift_samples_module {

class shift_samples_impl : public shift_samples
{
private:
    const size_t d_type_size;
    int d_number_of_samples_to_shift;
    int d_vector_length;

public:
    shift_samples_impl(size_t type_size,
                       int vector_length,
                       int number_of_samples_to_shift);
    ~shift_samples_impl();

    void set_number_of_samples_to_shift(int number_of_samples_to_shift) override
    {
        d_number_of_samples_to_shift = number_of_samples_to_shift;
    }
    int number_of_samples_to_shift() const override
    {
        return d_number_of_samples_to_shift;
    }

    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace shift_samples_module
} // namespace gr

#endif /* INCLUDED_SHIFT_SAMPLES_MODULE_SHIFT_SAMPLES_IMPL_H */
