
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk: virtual public MutableBinaryTree<Data> {
  // Must extend MutableBinaryTree<Data>

protected:

  using Container::size;

  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

  struct NodeLnk : virtual MutableNode { // Must extend MutableNode
  public:
  
    friend class BinaryTreeLnk<Data>;
    // ...
    Data element;
    NodeLnk* leftChild = nullptr;
    NodeLnk* rightChild = nullptr;

    NodeLnk(const Data& dat) : element(dat) {};
    NodeLnk(Data&& dat) noexcept : element(std::move(dat)) {};

    NodeLnk(const NodeLnk&);
    NodeLnk(NodeLnk&&) noexcept;

    virtual ~NodeLnk();

    NodeLnk& operator=(const NodeLnk&);
    NodeLnk& operator=(NodeLnk&&) noexcept;

    bool operator==(const NodeLnk&) const noexcept;
    bool operator!=(const NodeLnk&) const noexcept;

    const Data& Element() const noexcept override;
    Data& Element() noexcept override;

    bool IsLeaf() const noexcept override;
    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;

    const Node& LeftChild() const override;
    const Node& RightChild() const override;

    MutableNode& LeftChild() override;
    MutableNode& RightChild() override;
  };

  NodeLnk* root = nullptr; 

public:

  // Default constructor
  // BinaryTreeLnk() specifiers;
  BinaryTreeLnk() = default;
  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a TraversableContainer
  BinaryTreeLnk(const TraversableContainer<Data>&);
  // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a MappableContainer
  BinaryTreeLnk(MappableContainer<Data>&&);
  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeLnk(argument) specifiers;
  BinaryTreeLnk(const BinaryTreeLnk&);

  // Move constructor
  // BinaryTreeLnk(argument) specifiers;
  BinaryTreeLnk(BinaryTreeLnk&&) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeLnk() specifiers;
  virtual ~BinaryTreeLnk();
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BinaryTreeLnk& operator=(const BinaryTreeLnk&);

  // Move assignment
  // type operator=(argument) specifiers;
  BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BinaryTreeLnk&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BinaryTreeLnk&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
  const Node& Root() const override;
  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)
  MutableNode& Root() override;
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
