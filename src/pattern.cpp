#include "pattern.h"
#include <string>
#include <algorithm>

using namespace std;

Pattern::Pattern(int length){
  notes_.resize(length);
  this->length(length);
}

int Pattern::length() const{
  return length_;
}

int Pattern::length(int new_length){
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

int Pattern::vector_length() const{
  return notes_.size();
}

void Pattern::clear(){
  notes_ = vector<Note>(length_);
}

void Pattern::clear_range(size_t begin, size_t end){
  fill(notes_.begin()+begin, notes_.end()+end, Note());
}

Note& Pattern::operator[](size_t idx){
  if(idx >= length_){
    throw out_of_range(to_string(idx));
  }
  return notes_.at(idx);
}

const Note& Pattern::operator[](size_t idx) const{
  return notes_.at(idx);
}
