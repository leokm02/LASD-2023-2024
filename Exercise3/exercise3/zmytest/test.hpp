#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../list/list.hpp"
#include "../vector/vector.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../iterator/iterator.hpp"
#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../bst/bst.hpp"
#include "../hashtable/hashtable.hpp"
#include "../hashtable/clsadr/htclsadr.hpp"
#include "../hashtable/opnadr/htopnadr.hpp"

#include <string>

#define VECTOR_ID 1
#define SORTVECTOR_ID 2
#define LIST_ID 3
#define STACKVEC_ID 4
#define STACKLST_ID 5
#define QUEUEVEC_ID 6
#define QUEUELST_ID 7
#define BTVEC_ID 8
#define BTLNK_ID 9
#define BST_ID 10
#define HSHOPN_ID 11
#define HSHCLS_ID 12

#define ITERPRE_ID 1
#define ITERIN_ID 2
#define ITERPOST_ID 3
#define ITERBREADTH_ID 4

#define INT_ID 1
#define FLOAT_ID 2
#define STRING_ID 3

#define DEFAULT_SIZE 10

void mytest();

unsigned short selectStructure();
unsigned short selectType();



template <typename Data>
void fillVector(lasd::Vector<Data> &);
void fillVector(lasd::Vector<int> &);
void fillVector(lasd::Vector<float> &);
void fillVector(lasd::Vector<std::string> &);

template <typename Data>
void fillList(lasd::List<Data> &);
void fillList(lasd::List<int> &);
void fillList(lasd::List<float> &);
void fillList(lasd::List<std::string> &);

template <typename Data>
void fillStack(lasd::Stack<Data> &);
void fillStack(lasd::Stack<int> &);
void fillStack(lasd::Stack<float> &);
void fillStack(lasd::Stack<std::string> &);

template <typename Data>
void fillQueue(lasd::Queue<Data> &);
void fillQueue(lasd::Queue<int> &);
void fillQueue(lasd::Queue<float> &);
void fillQueue(lasd::Queue<std::string> &);

template <typename Data>
void fillHashTable(lasd::HashTable<Data> &);
void fillHashTable(lasd::HashTable<int> &);
void fillHashTable(lasd::HashTable<double> &);
void fillHashTable(lasd::HashTable<std::string> &);




template <typename Data>
void testVector(lasd::Vector<Data> &);
template <typename Data>
void testSortableVector(lasd::SortableVector<Data> &);
template <typename Data>
void testList(lasd::List<Data> &);
template <typename Data>
void testStack(lasd::Stack<Data> &);
template <typename Data>
void testQueue(lasd::Queue<Data> &);
template <typename Data>
void testBinaryTree(lasd::MutableBinaryTree<Data> &);
template <typename Data>
void testBST(lasd::BST<Data> &);
template <typename Data>
void testHashTable(lasd::HashTable<Data> &);

template <typename Data>
void testPreOrderIterator(lasd::BTPreOrderIterator<Data> &);
template <typename Data>
void testPostOrderIterator(lasd::BTPostOrderIterator<Data> &);
template <typename Data>
void testInOrderIterator(lasd::BTInOrderIterator<Data> &);
template <typename Data>
void testBreadthIterator(lasd::BTBreadthIterator<Data> &);



int generateInt();
float generateFloat();
std::string generateString();

template <typename Data>
void getValue(Data &){}
void getValue(int &);
void getValue(unsigned short &);
void getValue(unsigned long &);
void getValue(float &);
void getValue(std::string &);

#endif