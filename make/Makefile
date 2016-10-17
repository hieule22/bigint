# Makefile for building BigInteger library.

# Points to the root of BigInteger, relative to where this file is.
BIGINT_DIR = ..

# Flags passed to the preprocessor.
CPPFLAGS += -I$(BIGINT_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra --pedantic

# All BigInteger headers.
BIGINT_HEADERS = $(BIGINT_DIR)/include/bigint/*.h \
		 $(BIGINT_DIR)/include/bigint/internal/*.h

BIGINT_SRCS_ = $(BIGINT_DIR)/src/*.cc $(BIGINT_HEADERS)

# For simplicity and to avoid depending on BigInteger's implementation details,
# the dependencies specified below are conservative and not optimized.

number-array.o: $(BIGINT_DIR)/include/bigint/internal/number-array.h \
		$(BIGINT_DIR)/src/number-array.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(BIGINT_DIR)/src/number-array.cc

clean:
	rm -f *.o
