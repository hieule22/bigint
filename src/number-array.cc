// Template definitions for NumberArray.
// Copyright 2016 Hieu Le.

#include "bigint/internal/number-array.h"

namespace bigint {

template <typename Block>
NumberArray<Block>::NumberArray() : capacity_(0), length_(0) {}

template <typename Block>
NumberArray<Block>::NumberArray(const std::size_t capacity)
    : capacity_(capacity), length_(0) {
  blocks_.resize(capacity_);
}

template <typename Block>
NumberArray<Block>::NumberArray(const NumberArray<Block>& x)
    : length_(x.length_), capacity_(length_), blocks_(x.blocks_) {}

template <typename Block>
NumberArray<Block>::NumberArray(const std::vector<Block>& blocks)
    : capacity_(blocks.size()), length_(blocks.size()), blocks_(blocks) {}

template <typename Block>
void NumberArray<Block>::Allocate(const std::size_t capacity) {
  // If the requested capacity is more than the current capacity.
  if (capacity > capacity_) {
    // Delete the old number array.
    blocks_.clear();
    // Allocate the new array.
    capacity_ = capacity;
    blocks_.resize(capacity);
  }
}

template <typename Block>
void NumberArray<Block>::AllocateAndCopy(const std::size_t capacity) {
  if (capacity > capacity_) {
    blocks_.resize(capacity);
  }
}

template <typename Block>
void NumberArray<Block>::operator = (const NumberArray<Block>& x) {
  // Calls like a = a have no effect. Catch them before the aliasing causes
  // a problem.
  if (this == &x)
    return;

  // Copy length.
  length_ = x.length_;
  if (capacity_ < length_) {
    capacity_ = length_;
  }
  blocks_ = x.blocks_;
}

template <typename Block>
std::size_t NumberArray<Block>::GetCapacity() const {
  return capacity_;
}

template <typename Block>
std::size_t NumberArray<Block>::GetLength() const {
  return length_;
}

template <typename Block>
Block NumberArray<Block>::GetBlock(const std::size_t index) const {
  return blocks_[index];
}

template <typename Block>
bool NumberArray<Block>::IsEmpty() const {
  return length_ == 0;
}

template <typename Block>
bool NumberArray<Block>::operator ==(const NumberArray<Block>& x) const {
  if (length_ != x.length_) {
    return false;  // Definite unequal.
  }

  // Compare corresponding blocks one by one.
  for (std::size_t i = 0; i < length_; ++i) {
    if (blocks_[i] != x.blocks_[i]) {
      return false;
    }
  }

  // No blocks differed, so the objects are equal.
  return true;
}

template <typename Block>
bool NumberArray<Block>::operator !=(const NumberArray<Block> &x) const {
  return !operator ==(x);
}

}  // namespace bigint
