/* -*- c++ -*- */
/*
 * Copyright 2024 gr-shift_samples_module author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_SHIFT_SAMPLES_MODULE_SHIFT_SAMPLES_IMPL_H
#define INCLUDED_SHIFT_SAMPLES_MODULE_SHIFT_SAMPLES_IMPL_H

#include <gnuradio/shift_samples_module/shift_samples.h>

namespace gr {
namespace shift_samples_module {

class shift_samples_impl : public shift_samples
{
private:
    // Nothing to declare in this block.

public:
    shift_samples_impl(int shift_value);
    ~shift_samples_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace shift_samples_module
} // namespace gr

#endif /* INCLUDED_SHIFT_SAMPLES_MODULE_SHIFT_SAMPLES_IMPL_H */
