
namespace lasd {

/* ************************************************************************** */
template <typename Data>
HashTableOpnAdr<Data>::HashNode::HashNode(const HashTableOpnAdr<Data>::HashNode& nod) : HashNode(){
    if (nod.status == Status::Full){
        element = nod.element;
        status = nod.status;
    }
}

template <typename Data>
HashTableOpnAdr<Data>::HashNode::HashNode(HashTableOpnAdr<Data>::HashNode&& nod) noexcept : HashNode() {
    if (nod.status == Status::Full){
        std::swap(element, nod.element);
        std::swap(status, nod.status);
    }
}

template <typename Data>
HashTableOpnAdr<Data>::HashNode& HashTableOpnAdr<Data>::HashNode::operator=(const HashTableOpnAdr<Data>::HashNode& nod){
    if (nod.status == Status::Full){
        element = nod.element;
        status = nod.status;
    }

    return *this;
}

template <typename Data>
HashTableOpnAdr<Data>::HashNode& HashTableOpnAdr<Data>::HashNode::operator=(HashTableOpnAdr<Data>::HashNode&& nod) noexcept {
    if (nod.status == Status::Full){
        std::swap(element, nod.element);
        std::swap(status, nod.status);
    }

    return *this;
}

template <typename Data>
bool HashTableOpnAdr<Data>::HashNode::operator==(const HashTableOpnAdr<Data>::HashNode& nod) const noexcept {
    if (status == Status::Full && nod.status == Status::Full){
        return element == nod.element;
    }
      else {
        return ((status == Status::Empty && nod.status == Status::Empty) || (status == Status::Removed && nod.status == Status::Removed));
    }
}

template <typename Data>
inline bool HashTableOpnAdr<Data>::HashNode::operator!=(const HashTableOpnAdr<Data>::HashNode& nod) const noexcept{
    return !(*this == nod);
}

/******************** HASHTABLE *******************/
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr() : HashTable<Data>() {
    table.Resize(tableSize);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long size) : HashTable<Data>(){
    tableSize = size;
    table.Resize(tableSize);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data>& con) : HashTableOpnAdr(){
    con.Traverse(
        [this](const Data& dat){
            Insert(dat);
        }
    );
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long size, const TraversableContainer<Data>& con) : HashTableOpnAdr(size){
    con.Traverse(
        [this](const Data& dat){
            Insert(dat);
        }
    );
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data>&& con) : HashTableOpnAdr() {
    con.Map(
        [this](Data& dat){
            Insert(std::move(dat));
        }
    );
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long size, MappableContainer<Data>&& con) : HashTableOpnAdr(size) {
    con.Map(
        [this](Data& dat){
            Insert(std::move(dat));
        }
    );
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data>& ht) : HashTable<Data>(ht){
    table = ht.table;
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& ht) noexcept : HashTable<Data>(std::move(ht)) {
    std::swap(table, ht.table);
}

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data>& ht) {
    HashTableOpnAdr* temp = new HashTableOpnAdr(ht);
    std::swap(*temp, *this);
    delete temp;

    return *this;
}

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data>&& ht) noexcept {
    HashTable<Data>::operator=(std::move(ht));
    std::swap(table, ht.table);

    return *this;
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data>& ht) const noexcept {
    if (size == ht.size){
        bool equal = true;

        table.Traverse(
            [ht, &equal](const typename HashTableOpnAdr<Data>::HashNode& nod){
                if (nod.status == Status::Full){
                    equal &= ht.Exists(nod.element);
                }
            }
        );

        return equal;
    }
    else {
        return false;
    }
}

template <typename Data>
inline bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr<Data>& ht) const noexcept {
    return !(*this == ht);
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& dat){
    unsigned long j = FindEmpty(dat);

    if (j != tableSize){
        table[j] = HashNode(dat);
        ++size;

        Expand();
        return true;
    }
    
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& dat){
    unsigned long j = FindEmpty(dat);

    if (j != tableSize){
        table[j] = HashNode(std::move(dat));
        ++size;

        Expand();
        return true;
    }

    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& dat){
    unsigned long j = Find(dat);

    if (j != tableSize){
        table[j].status = Status::Removed;
        --size;

        Reduce();
        return true;
    }
    
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& dat) const noexcept{
    return (Find(dat) != tableSize);
}

template <typename Data>
void HashTableOpnAdr<Data>::Resize(const unsigned long newsize) {
    if (newsize == 0){
        Clear();
    }

    HashTableOpnAdr* temp; 
    if (newsize > size * 2) {
        temp = new HashTableOpnAdr(newsize);
    }
    else{
        temp = new HashTableOpnAdr(size * 2);
    }

    table.Map(
        [temp](typename HashTableOpnAdr<Data>::HashNode& nod){
            if (nod.status == Status::Full){
                temp->Insert(std::move(nod.element));
            }
        }
    );

    std::swap(*temp, *this);
    delete temp;
}

template <typename Data>
void HashTableOpnAdr<Data>::Clear() {
    for(unsigned long i = 0; i < tableSize; ++i){
        table[i].status = Status::Removed;
    }
    size = 0;
}

template <typename Data>
unsigned long HashTableOpnAdr<Data>::HashKey(const unsigned long key, const unsigned long index) const noexcept {
    return (((key + (index * index + index) / 2)) % tableSize);
}

template <typename Data>
unsigned long HashTableOpnAdr<Data>::Find(const Data& dat) const noexcept{
    unsigned long i = 0;
    unsigned long j;

    do {
        j = HashKey(HashKey(dat), i);

        if (table[j].status == Status::Empty){
            return tableSize;
        }

        if (table[j].status == Status::Full && table[j].element == dat){
            return j;
        }
        else { ++i; }
    }
    while (i < tableSize);

    return tableSize;
}

template <typename Data>
void HashTableOpnAdr<Data>::Remove(const Data& dat, unsigned long i){
    ++i;
    unsigned long j;

    do{
        j = HashKey(HashKey(dat), i);

        if (table[j].status == Status::Empty){
            return;
        }

        if (table[j].status == Status::Full && table[j].element == dat){
            table[j].status = Status::Removed;
            --size;
            return;
        }

        else { ++i; }
    }
    while(i < tableSize);

    return;
}

template <typename Data>
unsigned long HashTableOpnAdr<Data>::FindEmpty(const Data& dat) noexcept{
    unsigned long i = 0;

    do {
        unsigned long j = HashKey(HashKey(dat), i);
        
        if (table[j].status == Status::Full && table[j].element == dat){
            return tableSize;
        }

        else if (table[j].status == Status::Empty) {
            return j;
        }

        else if (table[j].status == Status::Removed){
            Remove(dat, i);
            return j;
        }
        else { ++i; }
    }
    while (i < tableSize);

    return tableSize;
}

template <typename Data>
void HashTableOpnAdr<Data>::Expand() {
    if (size >= tableSize / 2) {
        Resize(tableSize * 2);
    }
}

template <typename Data>
void HashTableOpnAdr<Data>::Reduce(){
    if (size <= tableSize / 8){
        Resize(tableSize / 2);
    }
}

/* ************************************************************************** */

}
