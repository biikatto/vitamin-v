/*! \class Pattern
 *  \brief A pattern, which holds notes for one track.
*/
#ifndef ___Vitamin_Pattern__
#define ___Vitamin_Pattern__
#include <vector>
#include "note.h"

using namespace std;

class Pattern{

  public:
    Pattern(unsigned int length=64);

    unsigned int length() const;
    unsigned int length(const unsigned int new_length);

    int vector_length() const;

    void clear();
    void clear_range(size_t begin, size_t end);

    Note& operator[](std::size_t idx);
    const Note& operator[](std::size_t idx) const;

    __wrap_iter<Note*> begin(){ return notes_.begin();}; /*!< Return an iterator pointing to the first Note in the pattern. */
    __wrap_iter<Note*> end(){ return notes_.end();}; /*!< Return an iterator pointing to the past-the-end Note in the pattern. */

    reverse_iterator<__wrap_iter<Note*> > rbegin(){ return notes_.rbegin();}; /*!< Return a reverse iterator pointing to the first Note in the reversed pattern. */
    reverse_iterator<__wrap_iter<Note*> > rend(){ return notes_.rend();}; /*!< Return a reverse iterator pointing to the past-the-end Note in the reversed pattern. */

    __wrap_iter<const Note*> cbegin(){ return notes_.cbegin();}; /*!< Return a const_iterator to the beginning. */
    __wrap_iter<const Note*> cend(){ return notes_.cend();}; /*!< Return a const_iterator to the end. */

    reverse_iterator<__wrap_iter<const Note*> > crbegin(){ return notes_.crbegin();}; /*!< Return a const_reverse_iterator to the beginning. */
    reverse_iterator<__wrap_iter<const Note*> > crend(){ return notes_.crend();}; /*!< Return a const_reverse_iterator to the end. */

  private:
    unsigned int length_;

    vector<Note> notes_;
};

#endif
