// A NumberArray holds a heap-allocated array of blocks with a specified length
// and capacity and provides basic memory management features.
// Copyright 2016 Hieu Le.

#ifndef BIGINT_INCLUDE_BIGINT_INTERNAL_NUMBER_ARRAY_H__
#define BIGINT_INCLUDE_BIGINT_INTERNAL_NUMBER_ARRAY_H__

#include <cstddef>

#include <vector>

namespace bigint {

template <typename Block>
class NumberArray {
 public:
  // Constructs a zero NumberArray without allocating a backing array.
  NumberArray();

  // Copy constructor.
  NumberArray(const NumberArray<Block>& x);

  // Constructs a zero NumberArray with the specified capacity.
  explicit NumberArray(std::size_t capacity);

  // Constructor that copies from a given array of blocks.
  explicit NumberArray(const std::vector<Block>& blocks);

  // Ensures that the array has at least the requested capacity.
  // May destroy the content.
  void Allocate(std::size_t capacity);

  // Ensures that the array has at least the requested capacity.
  // Will not destroy the content.
  void AllocateAndCopy(std::size_t capacity);

  // Copy assignment operator.
  void operator = (const NumberArray<Block>& x);

  // Accessors.
  std::size_t GetCapacity() const;
  std::size_t GetLength() const;
  Block GetBlock(std::size_t index) const;
  bool IsEmpty() const;

  // Equality comparisons: checks if both arrays have the same length and equal
  // (==) array elements to that length.
  bool operator == (const NumberArray& x) const;
  bool operator != (const NumberArray& x) const;

 private:
  // The current allocated capacity of this NumberArray (in blocks).
  std::size_t capacity_;
  // The actual length of the value stored in this NumberArray (in blocks).
  std::size_t length_;
  // Dynamically allocated array of the blocks.
  std::vector<Block> blocks_;
};

}  // namespace bigint

#endif  // BIGINT_INCLUDE_BIGINT_INTERNAL_NUMBER_ARRAY_H__
