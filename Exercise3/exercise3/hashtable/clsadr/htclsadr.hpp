
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr: virtual public HashTable<Data> {


protected:

  using Container::size;

  using HashTable<Data>::tableSize;
  using HashTable<Data>::hash;
  using HashTable<Data>::a;
  using HashTable<Data>::b;
  using HashTable<Data>::HashKey;
  using HashTable<Data>::Insert;
  using HashTable<Data>::InsertAll;

  Vector<List<Data>> table;

public:

  // Default constructor
  // HashTableClsAdr() specifiers
  HashTableClsAdr();
  /* ************************************************************************ */

  // Specific constructors
  HashTableClsAdr(const unsigned long); 
  HashTableClsAdr(const TraversableContainer<Data>&);
  HashTableClsAdr(const unsigned long, const TraversableContainer<Data>&);
  HashTableClsAdr(MappableContainer<Data>&&);
  HashTableClsAdr(const unsigned long, MappableContainer<Data>&&);
  /* ************************************************************************ */

  // Copy constructor
  HashTableClsAdr(const HashTableClsAdr&);
  // Move constructor
  HashTableClsAdr(HashTableClsAdr&&) noexcept;
  /* ************************************************************************ */

  // Destructor
  virtual ~HashTableClsAdr() = default;
  /* ************************************************************************ */

  // Copy assignment
  HashTableClsAdr& operator=(const HashTableClsAdr&);
  // Move assignment
  HashTableClsAdr& operator=(HashTableClsAdr&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableClsAdr&) const noexcept;
  bool operator!=(const HashTableClsAdr&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data&) override; 
  bool Insert(Data&&) override;
  bool Remove(const Data&) override;
  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data&) const noexcept override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  void Resize(const unsigned long) override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  void Clear() override;
};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
