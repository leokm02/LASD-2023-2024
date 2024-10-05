
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  unsigned long operator()(const Data&) const noexcept = 0;

};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public ResizableContainer,
                  virtual public DictionaryContainer<Data> {

protected:

  using Container::size;

  unsigned long a = 1;
  unsigned long b = 0;
  static const unsigned long p = 1000000007;

  std::default_random_engine gen = std::default_random_engine(std::random_device{}());
  std::uniform_int_distribution<unsigned long> distA = std::uniform_int_distribution<unsigned long>(1, p-1);
  std::uniform_int_distribution<unsigned long> distB = std::uniform_int_distribution<unsigned long>(0, p-1);

  static const Hashable<Data> hash;
  unsigned long tableSize = 128;

  HashTable();
  HashTable(const HashTable&);
  HashTable(HashTable&&) noexcept;
  HashTable& operator=(const HashTable&);
  HashTable& operator=(HashTable&&) noexcept;

public:

  // Destructor
  virtual ~HashTable() = default;

  // Comparison operators
  bool operator==(const HashTable&) const noexcept = delete;
  bool operator!=(const HashTable&) const noexcept = delete;

protected:

  // Auxiliary member functions
  unsigned long HashKey(const Data&) const noexcept;
  unsigned long HashKey(const unsigned long) const noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
