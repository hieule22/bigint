// A BigInteger object represents an immutable signed integer of size limited
// only by available memory. BigIntegers support most mathematical operations.
// Copyright 2016 Hieu Le.

#ifndef BIGINT_INCLUDE_BIGINT_BIG_INTEGER_H__
#define BIGINT_INCLUDE_BIGINT_BIG_INTEGER_H__

#include <cstdint>

#include <string>
#include <vector>

namespace bigint {

class BigInteger {
 public:
  // Enumeration for the sign of a BigInteger.
  enum class Sign : int {
      kNegative = -1,
      kZero     = 0,
      kPositive = 1,
  };

  // Copy constructor.
  explicit BigInteger(const BigInteger& other);

  // Translates the decimal String representation of a BigInteger into a
  // BigInteger
  explicit BigInteger(const std::string& val);

  // Returns a BigInteger whose value is the absolute value of this BigInteger.
  BigInteger GetMagnitude() const;

  // Converters to primitive integral types.
  int64_t  ToLong() const;
  uint64_t ToUnsignedLong() const;
  int32_t  ToInt() const;
  uint32_t ToUnsignedInt() const;

  // COMPARISONS.

  // Compares this BigInteger with the specified BigInteger.
  int CompareTo(const BigInteger& val) const;

  // Ordinary comparison operators.
  bool operator == (const BigInteger& val) const;
  bool operator != (const BigInteger& val) const;
  bool operator <  (const BigInteger& val) const;
  bool operator <= (const BigInteger& val) const;
  bool operator >  (const BigInteger& val) const;
  bool operator >= (const BigInteger& val) const;

  // OPERATORS.
  BigInteger Add(const BigInteger& val) const;
  BigInteger Subtract(const BigInteger& val) const;
  BigInteger Multiply(const BigInteger& val) const;
  BigInteger Divide(const BigInteger& val) const;
  std::vector<BigInteger> DivideWithRemainder(const BigInteger& val) const;

  // Ordinary operators.
  BigInteger operator + (const BigInteger& val) const;
  BigInteger operator - (const BigInteger& val) const;
  BigInteger operator * (const BigInteger& val) const;
  BigInteger operator / (const BigInteger& val) const;
  BigInteger operator % (const BigInteger& val) const;
};

}  // namespace bigint

#endif  // BIGINT_INCLUDE_BIGINT_BIG_INTEGER_H__
