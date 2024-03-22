/* -*- c++ -*- */
/*
 * Copyright 2024 gr-shift_samples_module author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_SHIFT_SAMPLES_MODULE_SHIFT_SAMPLES_H
#define INCLUDED_SHIFT_SAMPLES_MODULE_SHIFT_SAMPLES_H

#include <gnuradio/shift_samples_module/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace shift_samples_module {

/*!
 * \brief <+description of block+>
 * \ingroup shift_samples_module
 *
 */
class SHIFT_SAMPLES_MODULE_API shift_samples : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<shift_samples> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of
     * shift_samples_module::shift_samples.
     *
     * To avoid accidental use of raw pointers, shift_samples_module::shift_samples's
     * constructor is in a private implementation
     * class. shift_samples_module::shift_samples::make is the public interface for
     * creating new instances.
     */
    static sptr make(int shift_value = 0);
};

} // namespace shift_samples_module
} // namespace gr

#endif /* INCLUDED_SHIFT_SAMPLES_MODULE_SHIFT_SAMPLES_H */
