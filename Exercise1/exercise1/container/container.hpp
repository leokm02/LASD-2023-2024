
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */


namespace lasd {
  
  const char * const ERRMSG_EMPTY_CONTAINER = "Error: Empty container!";
  const char * const ERRMSG_OUT_OF_BOUNDS = "Error: Index is out of bounds!";
/* ************************************************************************** */

class Container {

protected:

  unsigned long size = 0;

public:

  // Destructor
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
  Container& operator=(const Container&) = delete; // Copy assignment of abstract types should not be possible.
  // Move assignment
  Container& operator=(Container&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Container&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const Container&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Empty() const noexcept {
    return (size == 0);
  } // (concrete function should not throw exceptions)

  virtual unsigned long Size() const noexcept {
    return size;
  } // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

class ClearableContainer: virtual public Container {

protected:

  using Container::size;

public:

  // Destructor
  virtual ~ClearableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ClearableContainer& operator=(const ClearableContainer&) = delete; // Copy assignment of abstract types should not be possible.
  // Move assignment
  ClearableContainer& operator=(ClearableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ClearableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const ClearableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function
  virtual void Clear() = 0;

};

/* ************************************************************************** */

class ResizableContainer: virtual public ClearableContainer {

protected:

  using Container::size;

public:

  // Destructor
  virtual ~ResizableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ResizableContainer& operator=(const ResizableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  ResizableContainer& operator=(ResizableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ResizableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const ResizableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function
  virtual void Resize(const unsigned long) = 0;

};

/* ************************************************************************** */

}

#endif
