
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */


template <typename Data>
class BinaryTreeVec: virtual public MutableBinaryTree<Data> {

protected:

  using Container::size;
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

  struct NodeVec: virtual MutableNode { // Must extend MutableNode
  public:
    
    friend class BinaryTreeVec<Data>;
    
    Data element;
    unsigned long int currIndex;
    Vector<NodeVec*> *treePtr = nullptr;         

    NodeVec(const Data&, unsigned long, Vector<NodeVec*>*);
    NodeVec(Data&&, unsigned long, Vector<NodeVec*>*);

    // NodeVec(const Data& dat) : element(dat) {};
    // NodeVec(Data&& dat) noexcept : element(std::move(dat)) {};

    NodeVec(const NodeVec&);
    NodeVec(NodeVec&&) noexcept;

    virtual ~NodeVec() = default;

    NodeVec& operator=(const NodeVec&);
    NodeVec& operator=(NodeVec&&) noexcept;

    bool operator==(const NodeVec&) const noexcept;
    bool operator!=(const NodeVec&) const noexcept;

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

  Vector<NodeVec*> treeVec;

public:

  // Default constructor
  // BinaryTreeVec() specifiers;
  BinaryTreeVec() = default;
  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a TraversableContainer
  BinaryTreeVec(const TraversableContainer<Data>&);
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a MappableContainer
  BinaryTreeVec(MappableContainer<Data>&&);
  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeVec(argument) specifiers;
  BinaryTreeVec(const BinaryTreeVec& alb);
  // Move constructor
  // BinaryTreeVec(argument) specifiers;
  BinaryTreeVec(BinaryTreeVec&& alb) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeVec() specifiers;
  virtual ~BinaryTreeVec();
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec& operator=(const BinaryTreeVec&);
  // Move assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BinaryTreeVec&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BinaryTreeVec&) const noexcept;
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
  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  // type BreadthTraverse(arguments) specifiers; // Override BreadthTraversableContainer member
  using typename TraversableContainer<Data>::TraverseFun;

  void BreadthTraverse(TraverseFun) const override;
  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member
  using typename MappableContainer<Data>::MapFun;

  void BreadthMap(MapFun) override;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
