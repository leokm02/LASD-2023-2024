
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data> {

protected:

  using Container::size;

  using HashTable<Data>::hash;
  using HashTable<Data>::a;
  using HashTable<Data>::b;
  using HashTable<Data>::distA;
  using HashTable<Data>::distB;
  using HashTable<Data>::gen;
  using HashTable<Data>::tableSize;
  using HashTable<Data>::HashKey;
  using HashTable<Data>::Insert;
  using HashTable<Data>::InsertAll;

  enum class Status {Empty, Full, Removed};

  struct HashNode {
    friend class HashTableOpnAdr<Data>;

    Data element;
    Status status = Status::Empty;

    HashNode() = default;
    HashNode(const Data& dat) : element(dat), status(Status::Full) {};
    HashNode(Data&& dat) : element(std::move(dat)), status(Status::Full) {};
    
    HashNode(const HashNode&);
    HashNode(HashNode&&) noexcept;

    HashNode& operator=(const HashNode&);
    HashNode& operator=(HashNode&&) noexcept;

    virtual ~HashNode() = default;

    bool operator==(const HashNode&) const noexcept;
    bool operator!=(const HashNode&) const noexcept;
  };

  Vector<HashNode> table;

public:

  //Default constructor
  HashTableOpnAdr();
  /* ************************************************************************ */

  // Specific constructors
  HashTableOpnAdr(const unsigned long);
  HashTableOpnAdr(const TraversableContainer<Data>&);
  HashTableOpnAdr(const unsigned long, const TraversableContainer<Data>&);
  HashTableOpnAdr(MappableContainer<Data>&&);
  HashTableOpnAdr(const unsigned long, MappableContainer<Data>&&);
  /* ************************************************************************ */

  // Copy constructor
  HashTableOpnAdr(const HashTableOpnAdr&);
  // Move constructor
  HashTableOpnAdr(HashTableOpnAdr&&) noexcept;
  /* ************************************************************************ */

  // Destructor
  virtual ~HashTableOpnAdr() = default;
  /* ************************************************************************ */

  // Copy assignment
  HashTableOpnAdr& operator=(const HashTableOpnAdr&);
  // Move assignment
  HashTableOpnAdr& operator=(HashTableOpnAdr&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableOpnAdr&) const noexcept;
  bool operator!=(const HashTableOpnAdr&) const noexcept;
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

protected:

  void Remove(const Data&, unsigned long);
  unsigned long HashKey(const unsigned long, const unsigned long) const noexcept;
  unsigned long Find(const Data&) const noexcept;
  unsigned long FindEmpty(const Data&) noexcept;

  void Expand();
  void Reduce();

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
