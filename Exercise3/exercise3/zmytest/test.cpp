#include "test.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
#include <random>
#include <limits>

void mytest(){

    unsigned short structure, type;

    do{
        structure = selectStructure();
        if(structure == 0) break;

        type = selectType();
        if(type == 0) continue;

        if(structure == VECTOR_ID){
            if(type == INT_ID){
                lasd::Vector<int> vec(DEFAULT_SIZE);
                fillVector(vec);
                testVector(vec);
            }
            else if(type == FLOAT_ID){
                lasd::Vector<float> vec(DEFAULT_SIZE);
                fillVector(vec);
                testVector(vec);
            }
            else if(type == STRING_ID){
                lasd::Vector<std::string> vec(DEFAULT_SIZE);
                fillVector(vec);
                testVector(vec);
            }
        }
        else if(structure == SORTVECTOR_ID){
            if(type == INT_ID){
                lasd::SortableVector<int> vec(DEFAULT_SIZE);
                fillVector(vec);
                testSortableVector(vec);
            }
            else if(type == FLOAT_ID){
                lasd::SortableVector<float> vec(DEFAULT_SIZE);
                fillVector(vec);
                testSortableVector(vec);
            }
            else if(type == STRING_ID){
                lasd::SortableVector<std::string> vec(DEFAULT_SIZE);
                fillVector(vec);
                testSortableVector(vec);
            }
        }
        else if(structure == LIST_ID){
            if(type == INT_ID){
                lasd::List<int> lst;
                fillList(lst);
                testList(lst);
            }
            else if(type == FLOAT_ID){
                lasd::List<float> lst;
                fillList(lst);
                testList(lst);
            }
            else if(type == STRING_ID){
                lasd::List<std::string> lst;
                fillList(lst);
                testList(lst);
            }
        }
        else if(structure == STACKVEC_ID){
            if(type == INT_ID){
                lasd::StackVec<int> stkvec;
                fillStack(stkvec);
                testStack(stkvec);
            }
            else if(type == FLOAT_ID){
                lasd::StackVec<float> stkvec;
                fillStack(stkvec);
                testStack(stkvec);
            }
            else if(type == STRING_ID){
                lasd::StackVec<std::string> stkvec;
                fillStack(stkvec);
                testStack(stkvec);
            }
        }
        else if(structure == STACKLST_ID){
            if(type == INT_ID){
                lasd::StackLst<int> stklst;
                fillStack(stklst);
                testStack(stklst);
            }
            else if(type == FLOAT_ID){
                lasd::StackLst<float> stklst;
                fillStack(stklst);
                testStack(stklst);
            }
            else if(type == STRING_ID){
                lasd::StackLst<std::string> stklst;
                fillStack(stklst);
                testStack(stklst);
            }
        }
        else if(structure == QUEUEVEC_ID){
            if(type == INT_ID){
                lasd::QueueVec<int> quevec;
                fillQueue(quevec);
                testQueue(quevec);
            }
            else if(type == FLOAT_ID){
                lasd::QueueVec<float> quevec;
                fillQueue(quevec);
                testQueue(quevec);
            }
            else if(type == STRING_ID){
                lasd::QueueVec<std::string> quevec;
                fillQueue(quevec);
                testQueue(quevec);
            }
        }
        else if(structure == QUEUELST_ID){
            if(type == INT_ID){
                lasd::QueueLst<int> quelst;
                fillQueue(quelst);
                testQueue(quelst);
            }
            else if(type == FLOAT_ID){
                lasd::QueueLst<float> quelst;
                fillQueue(quelst);
                testQueue(quelst);
            }
            else if(type == STRING_ID){
                lasd::QueueLst<std::string> quelst;
                fillQueue(quelst);
                testQueue(quelst);
            }
        }
        else if(structure == BTVEC_ID){
            if(type == INT_ID){
                lasd::List<int> lst;
                fillList(lst);
                lasd::BinaryTreeVec<int> btvec(lst);
                testBinaryTree(btvec);
            }
            else if(type == FLOAT_ID){
                lasd::List<float> lst;
                fillList(lst);
                lasd::BinaryTreeVec<float> btvec(lst);
                testBinaryTree(btvec);
            }
            else if(type == STRING_ID){
                lasd::List<std::string> lst;
                fillList(lst);
                lasd::BinaryTreeVec<std::string> btvec(lst);
                testBinaryTree(btvec);
            }
        }
        else if(structure == BTLNK_ID){
            if(type == INT_ID){
                lasd::List<int> lst;
                fillList(lst);
                lasd::BinaryTreeLnk<int> btlnk(lst);
                testBinaryTree(btlnk);
            }
            else if(type == FLOAT_ID){
                lasd::List<float> lst;
                fillList(lst);
                lasd::BinaryTreeLnk<float> btlnk(lst);
                testBinaryTree(btlnk);
            }
            else if(type == STRING_ID){
                lasd::List<std::string> lst;
                fillList(lst);
                lasd::BinaryTreeLnk<std::string> btlnk(lst);
                testBinaryTree(btlnk);
            }
        }
        else if(structure == BST_ID){
            if(type == INT_ID){
                lasd::List<int> lst;
                fillList(lst);
                lasd::BST<int> bst(lst);
                testBST(bst);
            }
            else if(type == FLOAT_ID){
                lasd::List<float> lst;
                fillList(lst);
                lasd::BST<float> bst(lst);
                testBST(bst);
            }
            else if(type == STRING_ID){
                lasd::List<std::string> lst;
                fillList(lst);
                lasd::BST<std::string> bst(lst);
                testBST(bst);
            }
        }
        else if(structure == HSHCLS_ID){
            if(type == INT_ID){
                lasd::HashTableClsAdr<int> hsh;
                fillHashTable(hsh);
                testHashTable(hsh);
            }
            else if(type == FLOAT_ID){
                lasd::HashTableClsAdr<double> hsh;
                fillHashTable(hsh);
                testHashTable(hsh);
            }
            else if(type == STRING_ID){
                lasd::HashTableClsAdr<std::string> hsh;
                fillHashTable(hsh);
                testHashTable(hsh);
            }
        }
        else if(structure == HSHOPN_ID){
            if(type == INT_ID){
                lasd::HashTableOpnAdr<int> hsh;
                fillHashTable(hsh);
                testHashTable(hsh);
            }
            else if(type == FLOAT_ID){
                lasd::HashTableOpnAdr<double> hsh;
                fillHashTable(hsh);
                testHashTable(hsh);
            }
            else if(type == STRING_ID){
                lasd::HashTableOpnAdr<std::string> hsh;
                fillHashTable(hsh);
                testHashTable(hsh);
            }
        }

    }while(true);
}





unsigned short selectStructure(){

    unsigned short parsed_input;

    std::cout << "\n\t!~~~~~~~ STUDENT TEST SUITE ~~~~~~~!\n";

    std::cout << "\n\tChoose the data structure:\n";

    std::cout << "\n\t(" << VECTOR_ID << ") Vector\n";
    std::cout << "\t(" << SORTVECTOR_ID << ") SortVector\n";
    std::cout << "\t(" << LIST_ID << ") List\n";
    std::cout << "\t(" << STACKVEC_ID << ") StackVec\n";
    std::cout << "\t(" << STACKLST_ID << ") StackLst\n";
    std::cout << "\t(" << QUEUEVEC_ID << ") QueueVec\n";
    std::cout << "\t(" << QUEUELST_ID << ") QueueLst\n";
    std::cout << "\t(" << BTVEC_ID << ") BinaryTreeVec\n";
    std::cout << "\t(" << BTLNK_ID << ") BinaryTreeLnk\n";
    std::cout << "\t(" << BST_ID << ") BST\n";
    std::cout << "\t(" << HSHOPN_ID << ") HashTableOpnAdr\n";
    std::cout << "\t(" << HSHCLS_ID << ") HashTableClsAdr\n";
    
    std::cout << "\n\t(0) to Exit\n";

    do{
        std::cout << "\n\t> ";

        try{
            getValue(parsed_input);

            if(
                parsed_input == 0 ||
                parsed_input == VECTOR_ID ||
                parsed_input == SORTVECTOR_ID ||
                parsed_input == LIST_ID ||
                parsed_input == STACKVEC_ID ||
                parsed_input == STACKLST_ID ||
                parsed_input == QUEUEVEC_ID ||
                parsed_input == QUEUELST_ID ||
                parsed_input == BTVEC_ID ||
                parsed_input == BTLNK_ID ||
                parsed_input == HSHCLS_ID ||
                parsed_input == HSHOPN_ID ||
                parsed_input == BST_ID
            ){
                break;
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::logic_error& err){
            std::cout << "[!] Invalid option. Please retry.\n";
        }

    }while(true);

    return parsed_input;
}

unsigned short selectType(){
    unsigned short parsed_input;

    std::cout << "\n\tChoose the type of stored data:\n";

    std::cout << "\n\t(" << INT_ID << ") int\n";
    std::cout << "\t(" << FLOAT_ID << ") float\n";
    std::cout << "\t(" << STRING_ID << ") string\n";
    std::cout << "\n\t(0) to Go Back\n";

    do{
        std::cout << "\n\t> ";

        try{
            getValue(parsed_input);

            if(
                parsed_input == 0 ||
                parsed_input == INT_ID ||
                parsed_input == FLOAT_ID ||
                parsed_input == STRING_ID
            ){
                break;
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::logic_error& err){
            std::cout << "[!] Invalid option. Please retry.\n";
        }

    }while(true);

    return parsed_input;
}





void fillVector(lasd::Vector<int> & vec){
    for(unsigned long i=0; i<vec.Size(); ++i){
        vec[i] = generateInt();
    }
}

void fillVector(lasd::Vector<float> & vec){    
    for(unsigned long i=0; i<vec.Size(); ++i){
        vec[i] = generateFloat();
    }
}

void fillVector(lasd::Vector<std::string> & vec){
    for(unsigned long i=0; i<vec.Size(); ++i){
        vec[i] = generateString();
    }
}





void fillList(lasd::List<int> & lst){
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        lst.Insert(generateInt());
    }
}

void fillList(lasd::List<float> & lst){    
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        lst.Insert(generateFloat());
    }
}

void fillList(lasd::List<std::string> & lst){
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        lst.Insert(generateString());
    }
}





void fillStack(lasd::Stack<int> & stk){
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        stk.Push(generateInt());
    }
}

void fillStack(lasd::Stack<float> & stk){    
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        stk.Push(generateFloat());
    }
}

void fillStack(lasd::Stack<std::string> & stk){
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        stk.Push(generateString());
    }
}





void fillQueue(lasd::Queue<int> & que){
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        que.Enqueue(generateInt());
    }
}

void fillQueue(lasd::Queue<float> & que){    
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        que.Enqueue(generateFloat());
    }
}

void fillQueue(lasd::Queue<std::string> & que){
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        que.Enqueue(generateString());
    }
}





void fillHashTable(lasd::HashTable<int> & ht){

    unsigned long parsed_input;

    do{
        std::cout << "\n\tInsert the amount of elements to generate [MIN: 1][MAX: 1.000.000]: \n";

        std::cout << "\n\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input && (parsed_input <= 1000000)){
                for(unsigned long i = 0; i<parsed_input; ++i) {
                    ht.Insert(generateInt());
                }
                break;
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::logic_error& err){
            std::cout << "\n\t[!] Invalid option. Please retry.\n";
        }

    }while(true);

}

void fillHashTable(lasd::HashTable<double> & ht){

    unsigned long parsed_input;

    do{
        std::cout << "\n\tInsert the amount of elements to generate [MIN: 1][MAX: 1.000.000]: \n";

        std::cout << "\n\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input && (parsed_input <= 1000000)){
                for(unsigned long i = 0; i<parsed_input; ++i) {
                    ht.Insert(static_cast<double>(generateFloat()));
                }
                break;
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::logic_error& err){
            std::cout << "\n\t[!] Invalid option. Please retry.\n";
        }

    }while(true);

}

void fillHashTable(lasd::HashTable<std::string> & ht){

    unsigned long parsed_input;

    do{
        std::cout << "\n\tInsert the amount of elements to generate [MIN: 1][MAX: 1.000.000]: \n";

        std::cout << "\n\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input && (parsed_input <= 1000000)){
                for(unsigned long i = 0; i<parsed_input; ++i) {
                    ht.Insert(generateString());
                }
                break;
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::logic_error& err){
            std::cout << "\n\t[!] Invalid option. Please retry.\n";
        }

    }while(true);

}





template <typename Data>
void testVector(lasd::Vector<Data> & con){

    const unsigned short OP_CLEAR = 1;
    const unsigned short OP_RESIZE = 2;
    const unsigned short OP_EXISTS = 3;
    const unsigned short OP_ASSIGN = 4;
    const unsigned short OP_FILL = 5;
    const unsigned short OP_SIZE = 6;
    const unsigned short OP_EMPTY = 7;

    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t!~~~~~~~ VECTOR ~~~~~~~!\n";

        std::cout << "\n\t\tSelect operation:\n";

        std::cout << "\n\t\t(" << OP_CLEAR << ") CLEAR: Clear container\n";
        std::cout << "\t\t(" << OP_RESIZE << ") RESIZE: Resize container\n";
        std::cout << "\t\t(" << OP_EXISTS << ") EXISTS: Check existence of value\n";
        std::cout << "\t\t(" << OP_ASSIGN << ") ASSIGN: Assign value to cell\n";
        std::cout << "\t\t(" << OP_FILL << ") FILL: Populate container with randomized values\n";
        std::cout << "\t\t(" << OP_SIZE << ") SIZE: Print container's size\n";
        std::cout << "\t\t(" << OP_EMPTY << ") EMPTY: Check if container is empty\n";
        std::cout << "\n\t\t(0) to Exit\n";

        std::cout << "\n\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_CLEAR){
                con.Clear();
                std::cout << "\n\t\tContainer successfully cleared!\n\n";
            }
            else if(parsed_input == OP_RESIZE){

                unsigned long newsize;

                std::cout << "\n\t\tInsert new [Size] for container (0 - 1000000) > ";

                getValue(newsize);

                if(newsize > 1000000){
                    throw std::out_of_range("Size value too big!");
                }

                con.Resize(newsize);

                std::cout << "\n\t\tContainer successfully resized!\n\n";
            }
            else if(parsed_input == OP_EXISTS){

                Data value;

                std::cout << "\n\t\tInsert the [Value] to search inside the container:\n";
                std::cout << "\n\t\t> ";

                getValue(value);

                if(con.Exists(value)){
                    std::cout << "\n\t\tValue \"" << value << "\" found!\n\n";
                }
                else{
                    std::cout << "\n\t\tValue \"" << value << "\" not found!\n\n";
                }
            }
            else if(parsed_input == OP_ASSIGN){
                unsigned long index;
                Data newvalue;

                std::cout << "\n\t\tInsert the [Index] of the cell:\n";
                std::cout << "\n\t\t> ";

                getValue(index);

                std::cout << "\n\t\tAssign the [Value]:\n";
                std::cout << "\n\t\t> ";

                getValue(newvalue);

                con[index] = newvalue;

                std::cout << "\n\t\tContainer successfully updated!\n\n";
            }
            else if(parsed_input == OP_FILL){
                std::cout << "\n\t\tRandomizing container contents...\n\n";
                fillVector(con);
                std::cout << "\n\t\tContainer successfully filled!\n\n";
            }
            else if(parsed_input == OP_SIZE){
                std::cout << "\n\t\tSize: " << con.Size() << "\n\n";
            }
            else if(parsed_input == OP_EMPTY){
                std::cout << "\n\t\tContainer is " << (con.Empty()?"":"not ") << "empty!\n\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n\t\t[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n\t\t[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n\t\t[!] Invalid option. Please retry.\n";
        }

    }while(true);

}

template <typename Data>
void testSortableVector(lasd::SortableVector<Data> & con){

    const unsigned short OP_CLEAR = 1;
    const unsigned short OP_RESIZE = 2;
    const unsigned short OP_EXISTS = 3;
    const unsigned short OP_ASSIGN = 4;
    const unsigned short OP_SORT = 5;
    const unsigned short OP_FILL = 6;
    const unsigned short OP_SIZE = 7;
    const unsigned short OP_EMPTY = 8;

    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t!~~~~~~~ SORTABLE VECTOR ~~~~~~~!\n";

        std::cout << "\n\t\tSelect operation:\n";

        std::cout << "\n\t\t(" << OP_CLEAR << ") CLEAR: Clear container\n";
        std::cout << "\t\t(" << OP_RESIZE << ") RESIZE: Resize container\n";
        std::cout << "\t\t(" << OP_EXISTS << ") EXISTS: Check existence of value\n";
        std::cout << "\t\t(" << OP_ASSIGN << ") ASSIGN: Assign value to cell\n";
        std::cout << "\t\t(" << OP_SORT << ") SORT: Sort container\n";
        std::cout << "\t\t(" << OP_FILL << ") FILL: Populate container with randomized values\n";
        std::cout << "\t\t(" << OP_SIZE << ") SIZE: Print container's size\n";
        std::cout << "\t\t(" << OP_EMPTY << ") EMPTY: Check if container is empty\n";
        std::cout << "\n\t\t(0) to Exit\n";

        std::cout << "\n\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_CLEAR){
                con.Clear();
                std::cout << "\n\t\tContainer successfully cleared!\n\n";
            }
            else if(parsed_input == OP_RESIZE){

                unsigned long newsize;

                std::cout << "\n\t\tInsert new [Size] for container (0 - 1000000) > ";

                getValue(newsize);

                if(newsize > 1000000){
                    throw std::out_of_range("Size value too big!");
                }

                con.Resize(newsize);

                std::cout << "\n\t\tContainer successfully resized!\n\n";
            }
            else if(parsed_input == OP_EXISTS){

                Data value;

                std::cout << "\n\t\tInsert the [Value] to search inside the container:\n";
                std::cout << "\n\t\t> ";

                getValue(value);

                if(con.Exists(value)){
                    std::cout << "\n\t\tValue \"" << value << "\" found!\n\n";
                }
                else{
                    std::cout << "\n\t\tValue \"" << value << "\" not found!\n\n";
                }
            }
            else if(parsed_input == OP_ASSIGN){
                unsigned long index;
                Data newvalue;

                std::cout << "\n\t\tInsert the [Index] of the cell:\n";
                std::cout << "\n\t\t> ";

                getValue(index);

                std::cout << "\n\t\tAssign the [Value]:\n";
                std::cout << "\n\t\t> ";

                getValue(newvalue);

                con[index] = newvalue;

                std::cout << "\n\t\tContainer successfully updated!\n\n";
            }
            else if(parsed_input == OP_SORT){
                con.Sort();
                std::cout << "\n\t\tContainer successfully sorted!\n\n";
            }
            else if(parsed_input == OP_FILL){
                std::cout << "\n\t\tRandomizing container contents...\n\n";
                fillVector(con);
                std::cout << "\n\t\tContainer successfully filled!\n\n";
            }
            else if(parsed_input == OP_SIZE){
                std::cout << "\n\t\tSize: " << con.Size() << "\n\n";
            }
            else if(parsed_input == OP_EMPTY){
                std::cout << "\n\t\tContainer is " << (con.Empty()?"":"not ") << "empty!\n\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n\t\t[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n\t\t[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n\t\t[!] Invalid option. Please retry.\n";
        }

    }while(true);

}

template <typename Data>
void testList(lasd::List<Data> & con){

    const unsigned short OP_CLEAR = 1;
    const unsigned short OP_EXISTS = 2;
    const unsigned short OP_DICTIONARY = 3;
    const unsigned short OP_LIST = 4;
    const unsigned short OP_FILL = 5;
    const unsigned short OP_SIZE = 6;
    const unsigned short OP_EMPTY = 7;

    const unsigned short OP_INSERT = 1;
    const unsigned short OP_REMOVE = 2;

    const unsigned short OP_INSERT_FRONT = 1;
    const unsigned short OP_INSERT_BACK = 2;
    const unsigned short OP_FRONT_N_REMOVE = 3;

    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t!~~~~~~~ LIST ~~~~~~~!\n";

        std::cout << "\n\t\tSelect operation:\n";

        std::cout << "\n\t\t(" << OP_CLEAR << ") CLEAR: Clear container\n";
        std::cout << "\t\t(" << OP_EXISTS << ") EXISTS: Check existence of value\n";
        std::cout << "\t\t(" << OP_DICTIONARY << ") DICTIONARY: Access to dictionary specific functions\n";
        std::cout << "\t\t(" << OP_LIST << ") LIST: Access to list specific functions\n";
        std::cout << "\t\t(" << OP_FILL << ") FILL: Populate container with randomized values\n";
        std::cout << "\t\t(" << OP_SIZE << ") SIZE: Print container's size\n";
        std::cout << "\t\t(" << OP_EMPTY << ") EMPTY: Check if container is empty\n";
        std::cout << "\n\t\t(0) to Exit\n";

        std::cout << "\n\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_CLEAR){
                con.Clear();
                std::cout << "\n\t\tContainer successfully cleared!\n\n";
            }
            else if(parsed_input == OP_EXISTS){

                Data value;

                std::cout << "\n\t\tInsert the [Value] to search inside the container:\n";
                std::cout << "\n\t\t> ";

                getValue(value);

                if(con.Exists(value)){
                    std::cout << "\n\t\tValue \"" << value << "\" found!\n\n";
                }
                else{
                    std::cout << "\n\t\tValue \"" << value << "\" not found!\n\n";
                }
            }
            else if(parsed_input == OP_DICTIONARY){

                unsigned short in;

                std::cout << "\n\t\tSelect the dictionary operation:\n";

                std::cout << "\n\t\t(" << OP_INSERT << ") INSERT: Insert value into dictionary\n";
                std::cout << "\t\t(" << OP_REMOVE << ") REMOVE: Remove value from dictionary\n";
                std::cout << "\n\t\t(0) to Exit\n";

                std::cout << "\n\t\t> ";

                getValue(in);

                if(in == 0){
                    continue;
                }
                else if(in == OP_INSERT){
                    Data value;

                    std::cout << "\n\t\tInsert the [Value] to insert:\n";
                    std::cout << "\n\t\t> ";

                    getValue(value);

                    if(con.Insert(value)){
                        std::cout << "\n\t\tThe value was successfully added to the dictionary!\n";
                    }
                    else{
                        std::cout << "\n\t\tInsert failed!\n";
                    }
                }
                else if(in == OP_REMOVE){
                    Data value;

                    std::cout << "\n\t\tInsert the [Value] to remove:\n";
                    std::cout << "\n\t\t> ";

                    getValue(value);

                    if(con.Remove(value)){
                        std::cout << "\n\t\tThe value was successfully removed from the dictionary!\n";
                    }
                    else{
                        std::cout << "\n\t\tRemove failed!\n";
                    }
                }
                else{
                    throw std::invalid_argument("");
                }

            }
            else if(parsed_input == OP_LIST){
                unsigned short in;
                
                std::cout << "\n\t\tSelect the list operation:\n";

                std::cout << "\n\t\t(" << OP_INSERT_FRONT << ") INSERT AT FRONT: Insert value at the front of the list\n";
                std::cout << "\t\t(" << OP_INSERT_BACK << ") INSERT AT BACK: Insert value at the back of the list\n";
                std::cout << "\t\t(" << OP_FRONT_N_REMOVE << ") FRONT & REMOVE: Remove and receive value from the front of the list\n";
                std::cout << "\n\t\t(0) to Exit\n";

                std::cout << "\n\t\t> ";

                getValue(in);

                if(in == 0){
                    continue;
                }
                else if(in == OP_INSERT_FRONT){
                    Data value;

                    std::cout << "\n\t\tInsert the [Value] to insert at front:\n";
                    std::cout << "\n\t\t> ";

                    getValue(value);

                    con.InsertAtFront(value);

                    std::cout << "\n\t\tThe value was successfully added to the front of the list!\n";
                    
                }
                else if(in == OP_INSERT_BACK){
                    Data value;

                    std::cout << "\n\t\tInsert the [Value] to insert at back:\n";
                    std::cout << "\n\t\t> ";

                    getValue(value);

                    con.InsertAtBack(value);

                    std::cout << "\n\t\tThe value was successfully added to the back of the list!\n";
                }
                else if(in == OP_FRONT_N_REMOVE){

                    Data res = con.FrontNRemove();
                    std::cout << "\n\t\tFront: " << res << "\n";

                    std::cout << "\n\t\tThe front of the list was successfully removed!\n";
                }
                else{
                    throw std::invalid_argument("");
                }
                
            }
            else if(parsed_input == OP_FILL){
                std::cout << "\n\t\tRandomizing container contents...\n\n";
                fillList(con);
                std::cout << "\n\t\tContainer successfully filled!\n\n";
            }
            else if(parsed_input == OP_SIZE){
                std::cout << "\n\t\tSize: " << con.Size() << "\n\n";
            }
            else if(parsed_input == OP_EMPTY){
                std::cout << "\n\t\tContainer is " << (con.Empty()?"":"not ") << "empty!\n\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n\t\t[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n\t\t[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n\t\t[!] Invalid option. Please retry.\n";
        }

    }while(true);
    
}

template <typename Data>
void testStack(lasd::Stack<Data> & con){

    const unsigned short OP_CLEAR = 1;
    const unsigned short OP_PUSH = 2;
    const unsigned short OP_TOP_N_POP = 3;
    const unsigned short OP_FILL = 4;
    const unsigned short OP_SIZE = 5;
    const unsigned short OP_EMPTY = 6;

    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t!~~~~~~~ STACK ~~~~~~~!\n";

        std::cout << "\n\t\tSelect operation:\n";

        std::cout << "\n\t\t(" << OP_CLEAR << ") CLEAR: Clear container\n";
        std::cout << "\t\t(" << OP_PUSH << ") PUSH: Push value onto stack\n";
        std::cout << "\t\t(" << OP_TOP_N_POP << ") TOP & POP: Pop value off stack and receive top\n";
        std::cout << "\t\t(" << OP_FILL << ") FILL: Populate container with randomized values\n";
        std::cout << "\t\t(" << OP_SIZE << ") SIZE: Print container's size\n";
        std::cout << "\t\t(" << OP_EMPTY << ") EMPTY: Check if container is empty\n";
        std::cout << "\n\t\t(0) to Exit\n";

        std::cout << "\n\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_CLEAR){
                con.Clear();
                std::cout << "\n\t\tContainer successfully cleared!\n\n";
            }
            else if(parsed_input == OP_PUSH){
                Data value;

                std::cout << "\n\t\tInsert the [Value] to push onto the top of the stack:\n";
                std::cout << "\n\t\t> ";

                getValue(value);

                con.Push(value);

                std::cout << "\n\t\tThe value was successfully pushed onto the stack!\n\n";
            }
            else if(parsed_input == OP_TOP_N_POP){
                Data res = con.TopNPop();
                std::cout << "\n\t\tTop: " << res << "\n";
                std::cout << "\n\t\tPop successful!\n\n";
            }
            else if(parsed_input == OP_FILL){
                std::cout << "\n\t\tRandomizing container contents...\n\n";
                fillStack(con);
                std::cout << "\n\t\tContainer successfully filled!\n\n";
            }
            else if(parsed_input == OP_SIZE){
                std::cout << "\n\t\tSize: " << con.Size() << "\n\n";
            }
            else if(parsed_input == OP_EMPTY){
                std::cout << "\n\t\tContainer is " << (con.Empty()?"":"not ") << "empty!\n\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n\t\t[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n\t\t[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n\t\t[!] Invalid option. Please retry.\n";
        }

    }while(true);

    
}

template <typename Data>
void testQueue(lasd::Queue<Data> & con){

    const unsigned short OP_CLEAR = 1;
    const unsigned short OP_ENQUEUE = 2;
    const unsigned short OP_HEAD_N_DEQUEUE = 3;
    const unsigned short OP_FILL = 4;
    const unsigned short OP_SIZE = 5;
    const unsigned short OP_EMPTY = 6;

    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t!~~~~~~~ QUEUE ~~~~~~~!\n";

        std::cout << "\n\t\tSelect operation:\n";

        std::cout << "\n\t\t(" << OP_CLEAR << ") CLEAR: Clear container\n";
        std::cout << "\t\t(" << OP_ENQUEUE << ") ENQUEUE: Enqueue value\n";
        std::cout << "\t\t(" << OP_HEAD_N_DEQUEUE << ") HEAD & DEQUEUE: Dequeue value and receive head\n";
        std::cout << "\t\t(" << OP_FILL << ") FILL: Populate container with randomized values\n";
        std::cout << "\t\t(" << OP_SIZE << ") SIZE: Print container's size\n";
        std::cout << "\t\t(" << OP_EMPTY << ") EMPTY: Check if container is empty\n";
        std::cout << "\n\t\t(0) to Exit\n";

        std::cout << "\n\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_CLEAR){
                con.Clear();
                std::cout << "\n\t\tContainer successfully cleared!\n\n";
            }
            else if(parsed_input == OP_ENQUEUE){
                Data value;

                std::cout << "\n\t\tInsert the [Value] to enqueue:\n";
                std::cout << "\n\t\t> ";

                getValue(value);

                con.Enqueue(value);

                std::cout << "\n\t\tThe value was successfully enqueued!\n\n";
            }
            else if(parsed_input == OP_HEAD_N_DEQUEUE){
                Data res = con.HeadNDequeue();
                std::cout << "\n\t\tHead: " << res << "\n";
                std::cout << "\n\t\tDequeue successful!\n\n";
            }
            else if(parsed_input == OP_FILL){
                std::cout << "\n\t\tRandomizing container contents...\n\n";
                fillQueue(con);
                std::cout << "\n\t\tContainer successfully filled!\n\n";
            }
            else if(parsed_input == OP_SIZE){
                std::cout << "\n\t\tSize: " << con.Size() << "\n\n";
            }
            else if(parsed_input == OP_EMPTY){
                std::cout << "\n\t\tContainer is " << (con.Empty()?"":"not ") << "empty!\n\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n\t\t[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n\t\t[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n\t\t[!] Invalid option. Please retry.\n";
        }

    }while(true);
}

template <typename Data>
void testBinaryTree(lasd::MutableBinaryTree<Data> & con){

    const unsigned short OP_CLEAR = 1;
    const unsigned short OP_EXISTS = 2;
    const unsigned short OP_ITER = 3;
    const unsigned short OP_SIZE = 4;
    const unsigned short OP_EMPTY = 5;

    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t!~~~~~~~ BINARY TREE ~~~~~~~!\n";

        std::cout << "\n\t\tSelect operation:\n";

        std::cout << "\n\t\t(" << OP_CLEAR << ") CLEAR: Clear container\n";
        std::cout << "\t\t(" << OP_EXISTS << ") EXISTS: Check existence of value\n";
        std::cout << "\t\t(" << OP_ITER << ") ITER: Open iterator testing suite\n";
        std::cout << "\t\t(" << OP_SIZE << ") SIZE: Print container's size\n";
        std::cout << "\t\t(" << OP_EMPTY << ") EMPTY: Check if container is empty\n";
        std::cout << "\n\t\t(0) to Exit\n";

        std::cout << "\n\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_CLEAR){
                con.Clear();
                std::cout << "\nContainer successfully cleared!\n\n";
            }
            else if(parsed_input == OP_EXISTS){

                Data value;

                std::cout << "\n\t\tInsert the [Value] to search inside the container:\n";
                std::cout << "\n\t\t> ";

                getValue(value);

                if(con.Exists(value)){
                    std::cout << "\nValue \"" << value << "\" found!\n\n";
                }
                else{
                    std::cout << "\nValue \"" << value << "\" not found!\n\n";
                }
            }
            else if(parsed_input == OP_ITER){
                unsigned short in;

                std::cout << "\n\t\tSelect iterator:\n";

                std::cout << "\n\t\t(" << ITERPRE_ID << ") PreOrder Iterator\n";
                std::cout << "\t\t(" << ITERIN_ID << ") InOrder Iterator\n";
                std::cout << "\t\t(" << ITERPOST_ID << ") PostOrder Iterator\n";
                std::cout << "\t\t(" << ITERBREADTH_ID << ") Breadth Iterator\n";
                std::cout << "\n\t\t(0) to Exit\n";

                std::cout << "\n\t\t> ";

                getValue(in);

                if(in == ITERPRE_ID){
                    lasd::BTPreOrderIterator<Data> iter(con);
                    testPreOrderIterator(iter);
                }
                else if(in == ITERIN_ID){
                    lasd::BTInOrderIterator<Data> iter(con);
                    testInOrderIterator(iter);
                }
                else if(in == ITERPOST_ID){
                    lasd::BTPostOrderIterator<Data> iter(con);
                    testPostOrderIterator(iter);
                }
                else if(in == ITERBREADTH_ID){
                    lasd::BTBreadthIterator<Data> iter(con);
                    testBreadthIterator(iter);
                }
                else{
                    throw std::invalid_argument("");
                }
            }
            else if(parsed_input == OP_SIZE){
                std::cout << "\n\t\tSize: " << con.Size() << "\n\n";
            }
            else if(parsed_input == OP_EMPTY){
                std::cout << "\n\t\tContainer is " << (con.Empty()?"":"not ") << "empty!\n\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n[!] Invalid option. Please retry.\n";
        }

    }while(true);
}

template <typename Data>
void testBST(lasd::BST<Data>& con){

    const unsigned short OP_CLEAR = 1;
    const unsigned short OP_EXISTS = 2;
    const unsigned short OP_ITER = 3;
    const unsigned short OP_INSERT = 4;
    const unsigned short OP_REMOVE = 5;
    const unsigned short OP_MIN_N_REMOVE = 6;
    const unsigned short OP_MAX_N_REMOVE = 7;
    const unsigned short OP_PREDECESSOR = 8;
    const unsigned short OP_PREDECESSOR_N_REMOVE = 9;
    const unsigned short OP_SUCCESSOR = 10;
    const unsigned short OP_SUCCESSOR_N_REMOVE = 11;
    const unsigned short OP_SIZE = 12;
    const unsigned short OP_EMPTY = 13;
    
    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t!~~~~~~~ BINARY SEARCH TREE ~~~~~~~!\n";

        std::cout << "\n\t\tSelect operation:\n";

        std::cout << "\n\t\t(" << OP_CLEAR << ") CLEAR: Clear container\n";
        std::cout << "\t\t(" << OP_EXISTS << ") EXISTS: Check existence of value\n";
        std::cout << "\t\t(" << OP_ITER << ") ITER: Open iterator testing suite\n";
        std::cout << "\t\t(" << OP_INSERT << ") INSERT: Insert new value into tree\n";
        std::cout << "\t\t(" << OP_REMOVE << ") REMOVE: Remove existing value from tree\n";
        std::cout << "\t\t(" << OP_MIN_N_REMOVE << ") MIN & REMOVE: Get minimum value\n";
        std::cout << "\t\t(" << OP_MAX_N_REMOVE << ") MAX & REMOVE: Get maximum value\n";
        std::cout << "\t\t(" << OP_PREDECESSOR << ") PREDECESSOR: Get predecessor\n";
        std::cout << "\t\t(" << OP_PREDECESSOR_N_REMOVE << ") PREDECESSOR & REMOVE: Remove predecessor\n";
        std::cout << "\t\t(" << OP_SUCCESSOR << ") SUCCESSOR: Get successor\n";
        std::cout << "\t\t(" << OP_SUCCESSOR_N_REMOVE << ") SUCCESSOR & REMOVE: Remove successor\n";
        std::cout << "\t\t(" << OP_SIZE << ") SIZE: Print container's size\n";
        std::cout << "\t\t(" << OP_EMPTY << ") EMPTY: Check if container is empty\n";
        std::cout << "\n\t\t(0) to Exit\n";

        std::cout << "\n\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_CLEAR){
                con.Clear();
                std::cout << "\nContainer successfully cleared!\n\n";
            }
            else if(parsed_input == OP_EXISTS){
                Data value;

                std::cout << "\n\t\tInsert the [Value] to search inside the container:\n";
                std::cout << "\n\t\t> ";

                getValue(value);

                if(con.Exists(value)){
                    std::cout << "\nValue \"" << value << "\" found!\n\n";
                }
                else{
                    std::cout << "\nValue \"" << value << "\" not found!\n\n";
                }
            }
            else if(parsed_input == OP_ITER){
                unsigned short in;

                std::cout << "\n\t\tSelect iterator:\n";

                std::cout << "\n\t\t(" << ITERPRE_ID << ") PreOrder Iterator\n";
                std::cout << "\t\t(" << ITERIN_ID << ") InOrder Iterator\n";
                std::cout << "\t\t(" << ITERPOST_ID << ") PostOrder Iterator\n";
                std::cout << "\t\t(" << ITERBREADTH_ID << ") Breadth Iterator\n";
                std::cout << "\n\t\t(0) to Exit\n";

                std::cout << "\n\t\t> ";

                getValue(in);

                if(in == ITERPRE_ID){
                    lasd::BTPreOrderIterator<Data> iter(con);
                    testPreOrderIterator(iter);
                }
                else if(in == ITERIN_ID){
                    lasd::BTInOrderIterator<Data> iter(con);
                    testInOrderIterator(iter);
                }
                else if(in == ITERPOST_ID){
                    lasd::BTPostOrderIterator<Data> iter(con);
                    testPostOrderIterator(iter);
                }
                else if(in == ITERBREADTH_ID){
                    lasd::BTBreadthIterator<Data> iter(con);
                    testBreadthIterator(iter);
                }
                else{
                    throw std::invalid_argument("");
                }
            }
            else if(parsed_input == OP_INSERT){
                Data value;

                std::cout << "\n\t\tInsert [Value]:\n\t\t> ";
                getValue(value);

                if(con.Insert(value)){
                    std::cout << "\nValue inserted successfully!\n";
                }
                else{
                    std::cout << "\nInsert failed!\n";
                }
            }
            else if(parsed_input == OP_REMOVE){
                Data value;

                std::cout << "\n\t\tInsert [Value]:\n\t\t> ";
                getValue(value);

                if(con.Remove(value)){
                    std::cout << "\nValue removed successfully!\n";
                }
                else{
                    std::cout << "\nRemove failed!\n";
                }
            }
            else if(parsed_input == OP_MIN_N_REMOVE){
                Data min = con.MinNRemove();

                std::cout << "\nMin: " << min << "\n";
                std::cout << "\nMin successfully removed from tree!\n";
            }
            else if(parsed_input == OP_MAX_N_REMOVE){
                Data min = con.MaxNRemove();

                std::cout << "\nMax: " << min << "\n";
                std::cout << "\nMax successfully removed from tree!\n";
            }
            else if(parsed_input == OP_PREDECESSOR){
                Data value;

                std::cout << "\n\t\tInsert [Value]:\n\t\t> ";
                getValue(value);

                Data pred = con.Predecessor(value);
                std::cout << "\nPredecessor of " << value << ": " << pred << "\n";
            }
            else if(parsed_input == OP_PREDECESSOR_N_REMOVE){
                Data value;

                std::cout << "\n\t\tInsert [Value]:\n\t\t> ";
                getValue(value);

                Data pred = con.PredecessorNRemove(value);
                std::cout << "\nPredecessor of " << value << ": " << pred << "\n";
                std::cout << "\nPredecessor successfully removed from tree!\n";
            }
            else if(parsed_input == OP_SUCCESSOR){
                Data value;

                std::cout << "\n\t\tInsert [Value]:\n\t\t> ";
                getValue(value);

                Data succ = con.Successor(value);
                std::cout << "\nSuccessor of " << value << ": " << succ << "\n";
            }
            else if(parsed_input == OP_SUCCESSOR_N_REMOVE){
                Data value;

                std::cout << "\n\t\tInsert [Value]:\n\t\t> ";
                getValue(value);

                Data succ = con.SuccessorNRemove(value);
                std::cout << "\nSuccessor of " << value << ": " << succ << "\n";
                std::cout << "\nSuccessor successfully removed from tree!\n";
            }
            else if(parsed_input == OP_SIZE){
                std::cout << "\n\t\tSize: " << con.Size() << "\n\n";
            }
            else if(parsed_input == OP_EMPTY){
                std::cout << "\n\t\tContainer is " << (con.Empty()?"":"not ") << "empty!\n\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n[!] Invalid option. Please retry.\n";
        }

    }while(true);
}

template <typename Data>
void testHashTable(lasd::HashTable<Data> & con)
{
    const unsigned short OP_INSERT = 1;
    const unsigned short OP_REMOVE = 2;
    const unsigned short OP_RESIZE = 3;
    const unsigned short OP_CLEAR = 4;
    const unsigned short OP_EXISTS = 5;
    const unsigned short OP_FILL = 6;
    const unsigned short OP_SIZE = 7;
    const unsigned short OP_EMPTY = 8;
    
    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t!~~~~~~~ HASH TABLE ~~~~~~~!\n";

        std::cout << "\n\t\tSelect operation:\n";

        std::cout << "\n\t\t(" << OP_INSERT << ") INSERT: Insert value into container\n";
        std::cout << "\t\t(" << OP_REMOVE << ") REMOVE: Remove value from container\n";
        std::cout << "\t\t(" << OP_RESIZE << ") RESIZE: Resize container\n";
        std::cout << "\t\t(" << OP_CLEAR << ") CLEAR: Clear container\n";
        std::cout << "\t\t(" << OP_EXISTS << ") EXISTS: Check if value exists within container\n";
        std::cout << "\t\t(" << OP_FILL << ") FILL: Populate container with values\n";
        std::cout << "\t\t(" << OP_SIZE << ") SIZE: Print container's size\n";
        std::cout << "\t\t(" << OP_EMPTY << ") EMPTY: Check if container is empty\n";
        std::cout << "\n\t\t(0) to Exit\n";

        std::cout << "\n\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_INSERT){
                Data value;

                std::cout << "\n\t\tInsert [Value]:\n\t\t> ";
                getValue(value);

                if(con.Insert(value)){
                    std::cout << "\nValue inserted successfully!\n";
                }
                else{
                    std::cout << "\nInsert failed!\n";
                }
            }
            else if(parsed_input == OP_REMOVE){
                Data value;

                std::cout << "\n\t\tInsert [Value]:\n\t\t> ";
                getValue(value);

                if(con.Remove(value)){
                    std::cout << "\nValue removed successfully!\n";
                }
                else{
                    std::cout << "\nRemove failed!\n";
                }
            }
            else if(parsed_input == OP_CLEAR){
                con.Clear();
                std::cout << "\nContainer successfully cleared!\n\n";
            }
            else if(parsed_input == OP_EXISTS){
                Data value;

                std::cout << "\n\t\tInsert the [Value] to search inside the container:\n";
                std::cout << "\n\t\t> ";

                getValue(value);

                if(con.Exists(value)){
                    std::cout << "\nValue \"" << value << "\" found!\n\n";
                }
                else{
                    std::cout << "\nValue \"" << value << "\" not found!\n\n";
                }
            }
            else if(parsed_input == OP_FILL){
                fillHashTable(con);
                std::cout << "\n\t\tContainer successfully filled!\n\n";
            }
            else if(parsed_input == OP_SIZE){
                std::cout << "\n\t\tSize: " << con.Size() << "\n\n";
            }
            else if(parsed_input == OP_EMPTY){
                std::cout << "\n\t\tContainer is " << (con.Empty()?"":"not ") << "empty!\n\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n[!] Invalid option. Please retry.\n";
        }

    }while(true);
}





template <typename Data>
void testPreOrderIterator(lasd::BTPreOrderIterator<Data> & iter){
    const unsigned short OP_VIEW = 1;
    const unsigned short OP_INCREMENT = 2;
    const unsigned short OP_RESET = 3;

    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t\t!~~~~~~~ PREORDER ITERATOR ~~~~~~~!\n";

        std::cout << "\n\t\t\tSelect operation:\n";

        std::cout << "\n\t\t\t(" << OP_VIEW << ") VIEW: View current element\n";
        std::cout << "\t\t\t(" << OP_INCREMENT << ") INCREMENT: Increment iterator\n";
        std::cout << "\t\t\t(" << OP_RESET << ") RESET: Reset iterator\n";
        std::cout << "\n\t\t\t(0) to Exit\n";

        std::cout << "\n\t\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_VIEW){
                Data currelem = *iter;
                std::cout << "\nCurrent element: " << currelem << "\n";
            }
            else if(parsed_input == OP_INCREMENT){
                ++iter;
                std::cout << "\nIterator incremented!\n";
            }
            else if(parsed_input == OP_RESET){
                iter.Reset();
                std::cout << "\nIterator reset!\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n[!] Invalid option. Please retry.\n";
        }

    }while(true);
}

template <typename Data>
void testPostOrderIterator(lasd::BTPostOrderIterator<Data> & iter){
    const unsigned short OP_VIEW = 1;
    const unsigned short OP_INCREMENT = 2;
    const unsigned short OP_RESET = 3;

    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t\t!~~~~~~~ POSTORDER ITERATOR ~~~~~~~!\n";

        std::cout << "\n\t\t\tSelect operation:\n";

        std::cout << "\n\t\t\t(" << OP_VIEW << ") VIEW: View current element\n";
        std::cout << "\t\t\t(" << OP_INCREMENT << ") INCREMENT: Increment iterator\n";
        std::cout << "\t\t\t(" << OP_RESET << ") RESET: Reset iterator\n";
        std::cout << "\n\t\t\t(0) to Exit\n";

        std::cout << "\n\t\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_VIEW){
                Data currelem = *iter;
                std::cout << "\nCurrent element: " << currelem << "\n";
            }
            else if(parsed_input == OP_INCREMENT){
                ++iter;
                std::cout << "\nIterator incremented!\n";
            }
            else if(parsed_input == OP_RESET){
                iter.Reset();
                std::cout << "\nIterator reset!\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n[!] Invalid option. Please retry.\n";
        }

    }while(true);
}

template <typename Data>
void testInOrderIterator(lasd::BTInOrderIterator<Data> & iter){
    const unsigned short OP_VIEW = 1;
    const unsigned short OP_INCREMENT = 2;
    const unsigned short OP_RESET = 3;

    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t\t!~~~~~~~ INORDER ITERATOR ~~~~~~~!\n";

        std::cout << "\n\t\t\tSelect operation:\n";

        std::cout << "\n\t\t\t(" << OP_VIEW << ") VIEW: View current element\n";
        std::cout << "\t\t\t(" << OP_INCREMENT << ") INCREMENT: Increment iterator\n";
        std::cout << "\t\t\t(" << OP_RESET << ") RESET: Reset iterator\n";
        std::cout << "\n\t\t\t(0) to Exit\n";

        std::cout << "\n\t\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_VIEW){
                Data currelem = *iter;
                std::cout << "\nCurrent element: " << currelem << "\n";
            }
            else if(parsed_input == OP_INCREMENT){
                ++iter;
                std::cout << "\nIterator incremented!\n";
            }
            else if(parsed_input == OP_RESET){
                iter.Reset();
                std::cout << "\nIterator reset!\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n[!] Invalid option. Please retry.\n";
        }

    }while(true);
}

template <typename Data>
void testBreadthIterator(lasd::BTBreadthIterator<Data> & iter){
    const unsigned short OP_VIEW = 1;
    const unsigned short OP_INCREMENT = 2;
    const unsigned short OP_RESET = 3;

    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t\t!~~~~~~~ BREADTH ITERATOR ~~~~~~~!\n";

        std::cout << "\n\t\t\tSelect operation:\n";

        std::cout << "\n\t\t\t(" << OP_VIEW << ") VIEW: View current element\n";
        std::cout << "\t\t\t(" << OP_INCREMENT << ") INCREMENT: Increment iterator\n";
        std::cout << "\t\t\t(" << OP_RESET << ") RESET: Reset iterator\n";
        std::cout << "\n\t\t\t(0) to Exit\n";

        std::cout << "\n\t\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_VIEW){
                Data currelem = *iter;
                std::cout << "\nCurrent element: " << currelem << "\n";
            }
            else if(parsed_input == OP_INCREMENT){
                ++iter;
                std::cout << "\nIterator incremented!\n";
            }
            else if(parsed_input == OP_RESET){
                iter.Reset();
                std::cout << "\nIterator reset!\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n[!] Invalid option. Please retry.\n";
        }

    }while(true);
}


int generateInt(){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> int_dist(0, 100);

    return int_dist(gen);
}

float generateFloat(){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<float> float_dist(0, 10);

    return float_dist(gen);
}

std::string generateString()
{
    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::string generateString;

    for (std::size_t i = 0; i < 5; ++i)
    {
        generateString += CHARACTERS[distribution(generator)];
    }

    return generateString;
}

void getValue(int & dat){
    std::string input;

    getline(std::cin, input);
    dat = std::stoi(input);
}

void getValue(unsigned short & dat){
    std::string input;

    getline(std::cin, input);
    dat = std::stoi(input);
}

void getValue(unsigned long & dat){
    std::string input;

    getline(std::cin, input);
    dat = std::stoul(input);
}

void getValue(float & dat){
    std::string input;

    getline(std::cin, input);
    dat = std::stof(input);
}

void getValue(std::string & dat){
    getline(std::cin, dat);
}

