// shift_samples.h
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
     * shift_samples_module::number_of_samples_to_shift.
     *
     * \param type_size Size of type of data
     * \param vector_length Size of vector
     * \param number_of_samples_to_shift Number os samples to shift
     */
    static sptr make(size_t type_size, int vector_length, int number_of_samples_to_shift);

    /*!
     * \brief Set the sample shift
     *
     * This method allows you to dynamically change the number_of_samples_to_shift of the
     * block.
     *
     * \param number_of_samples_to_shift The new number_of_samples_to_shift
     */
    virtual void set_number_of_samples_to_shift(int number_of_samples_to_shift) = 0;
    virtual int number_of_samples_to_shift() const = 0;
};

} // namespace shift_samples_module
} // namespace gr

#endif /* INCLUDED_SHIFT_SAMPLES_MODULE_SHIFT_SAMPLES_H */
