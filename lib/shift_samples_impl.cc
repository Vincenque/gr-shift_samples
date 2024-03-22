/* -*- c++ -*- */
/*
 * Copyright 2024 gr-shift_samples_module author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "shift_samples_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace shift_samples_module {

#pragma message("set the following appropriately and remove this warning")
using input_type = float;
#pragma message("set the following appropriately and remove this warning")
using output_type = float;
shift_samples::sptr shift_samples::make(int shift_value)
{
    return gnuradio::make_block_sptr<shift_samples_impl>(shift_value);
}


/*
 * The private constructor
 */
shift_samples_impl::shift_samples_impl(int shift_value)
    : gr::sync_block("shift_samples",
                     gr::io_signature::make(
                         1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type)))
{
}

/*
 * Our virtual destructor.
 */
shift_samples_impl::~shift_samples_impl() {}

int shift_samples_impl::work(int noutput_items,
                             gr_vector_const_void_star& input_items,
                             gr_vector_void_star& output_items)
{
    auto in = static_cast<const input_type*>(input_items[0]);
    auto out = static_cast<output_type*>(output_items[0]);

#pragma message("Implement the signal processing in your block and remove this warning")
    // Do <+signal processing+>

    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace shift_samples_module */
} /* namespace gr */
