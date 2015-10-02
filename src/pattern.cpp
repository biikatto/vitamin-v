#include "pattern.h"
#include <string>
#include <algorithm>

using namespace std;

//! Default constructor.
Pattern::Pattern(unsigned int length){
  notes_.resize(length);
  this->length(length);
}

//! Return the length of the pattern.
unsigned int Pattern::length() const{
  return length_;
}

//! Set the length of the pattern and return it.
unsigned int Pattern::length(unsigned int new_length){
  if(new_length > 0){
    // resize vectors only if new length is greater
    // (we don't want to destructively resize in case
    // we want to undo a pattern length change)
    if(new_length > length_){
      notes_.resize(new_length);
    }
    length_ = new_length;
  }
  return length_;
}

//! Return the length of the underlying Note vector.
int Pattern::vector_length() const{
  return notes_.size();
}

//! Clear the pattern.
void Pattern::clear(){
  notes_ = vector<Note>(length_);
}

//! Clear a range of Notes in the pattern, from indexes begin to end.
void Pattern::clear_range(size_t begin, size_t end){
  fill(notes_.begin()+begin, notes_.end()+end, Note());
}

//! Return a reference to a Note in the pattern at position idx.
Note& Pattern::operator[](size_t idx){
  if(idx >= length_){
    throw out_of_range(to_string(idx));
  }
  return notes_.at(idx);
}

//! Return a const reference to a Note in the pattern at position idx.
const Note& Pattern::operator[](size_t idx) const{
  return notes_.at(idx);
}
