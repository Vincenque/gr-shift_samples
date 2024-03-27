// shift_samples.h
#ifndef INCLUDED_SHIFT_SAMPLES_MODULE_SHIFT_SAMPLES_H
#define INCLUDED_SHIFT_SAMPLES_MODULE_SHIFT_SAMPLES_H

#include <gnuradio/shift_samples_module/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace shift_samples_module {

/*!
 * \brief This class represents a block that shifts samples in a GNU Radio flowgraph.
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
     * \param type_size The size of each data item in bytes.
     * \param vector_length The length of the vectors that the block will process.
     * \param number_of_samples_to_shift The number of samples by which to shift the input
     * data.
     */
    static sptr make(size_t type_size, int vector_length, int number_of_samples_to_shift);

    /*!
     * \brief Set the sample shift.
     *
     * This method allows you to dynamically change the number of samples by which the
     * input data is shifted.
     *
     * \param number_of_samples_to_shift The new number of samples to shift.
     */
    virtual void set_number_of_samples_to_shift(int number_of_samples_to_shift) = 0;
    virtual int number_of_samples_to_shift() const = 0;
};

} // namespace shift_samples_module
} // namespace gr

#endif /* INCLUDED_SHIFT_SAMPLES_MODULE_SHIFT_SAMPLES_H */
