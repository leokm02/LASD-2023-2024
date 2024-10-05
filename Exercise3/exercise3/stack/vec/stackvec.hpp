
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec: virtual public Stack<Data>,
                virtual protected Vector<Data> {

private:

  // ...

protected:

  static const unsigned long DEFAULT_CAPACITY = 10;

  using Container::size;
  using Vector<Data>::elements;
  unsigned long topIndex = 0;

public:

  // Default constructor
  StackVec() : Vector<Data>(DEFAULT_CAPACITY) {}

  /* ************************************************************************ */

  // Specific constructor
  StackVec(const TraversableContainer<Data>&); // A stack obtained from a MappableContainer
  StackVec(MappableContainer<Data>&&) noexcept; // A stack obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec&);

  // Move constructor
  StackVec(StackVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackVec& operator=(const StackVec&);

  // Move assignment
  StackVec& operator=(StackVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackVec&) const noexcept;
  bool operator!=(const StackVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  const Data& Top() const override; // (non-mutable version; concrete function must throw std::length_error when empty)
  Data& Top() override; // (mutable version; concrete function must throw std::length_error when empty)
  void Pop() override; // (concrete function must throw std::length_error when empty)
  Data TopNPop() override; // (concrete function must throw std::length_error when empty)
  void Push(const Data&) override; // Copy of the value
  void Push(Data&&) noexcept override; // Move of the value

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  bool Empty() const noexcept override; // Override Container member

  unsigned long Size() const noexcept override; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member
  

protected:

  void Expand();
  void Reduce();

  // Specific member function (inherited from LinearContainer)

  using typename TraversableContainer<Data>::TraverseFun;
  void Traverse(TraverseFun) const override;

  using typename MappableContainer<Data>::MapFun;
  void Map(MapFun) override;

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
