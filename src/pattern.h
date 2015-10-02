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

    // Wrapper for underlying Note vector
    Note& operator[](std::size_t idx);
    const Note& operator[](std::size_t idx) const;

    __wrap_iter<Note*> begin(){ return notes_.begin();};
    __wrap_iter<Note*> end(){ return notes_.end();};

    reverse_iterator<__wrap_iter<Note*> > rbegin(){ return notes_.rbegin();};
    reverse_iterator<__wrap_iter<Note*> > rend(){ return notes_.rend();};

    __wrap_iter<const Note*> cbegin(){ return notes_.cbegin();};
    __wrap_iter<const Note*> cend(){ return notes_.cend();};

    reverse_iterator<__wrap_iter<const Note*> > crbegin(){ return notes_.crbegin();};
    reverse_iterator<__wrap_iter<const Note*> > crend(){ return notes_.crend();};

  private:
    unsigned int length_;

    vector<Note> notes_;
};

#endif
