
namespace lasd {

/* ************************************************************************** */
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr() : HashTable<Data>() {
    table.Resize(tableSize);

    for (unsigned long i = 0; i < tableSize; ++i){
       table[i] = List<Data>();
    }
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const unsigned long size) : HashTable<Data>() {
    tableSize = size;
    table.Resize(tableSize);

    for (unsigned long i = 0; i < tableSize; ++i){
       table[i] = List<Data>();
    }
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data>& con) : HashTableClsAdr<Data>() {
    con.Traverse(
        [this](const Data& dat){
            Insert(dat);
        }
    );
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const unsigned long size, const TraversableContainer<Data>& con) : HashTableClsAdr<Data>(size) {
    con.Traverse(
        [this](const Data& dat){
            Insert(dat);
        }
    );
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data>&& con) : HashTableClsAdr<Data>() {
    con.Map(
        [this](Data& dat){
            Insert(std::move(dat));
        }
    );
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const unsigned long size, MappableContainer<Data>&& con) : HashTableClsAdr<Data>(size) {
    con.Map(
        [this](Data& dat){
            Insert(std::move(dat));
        }
    );
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& ht) : HashTable<Data>(ht) {
    table = ht.table;
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& ht) noexcept : HashTable<Data>(std::move(ht)) {
    std::swap(table, ht.table);
}

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data>& ht){
    HashTableClsAdr* tmp = new HashTableClsAdr(ht);
    std::swap(*this, *tmp);
    delete tmp;

    return *this;
}

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data>&& ht) noexcept{
    HashTable<Data>::operator=(std::move(ht));
    std::swap(table, ht.table);

    return *this;
}

template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data>& ht) const noexcept {
    if (size == ht.size){
        bool equal = true;

        for (unsigned long i = 0; i < tableSize; ++i){
            table[i].Traverse(
                [ht, &equal](const Data& dat){             //deve controllare per ogni elemento delle liste di table se esiste in ht
                    equal &= ht.Exists(dat);
                }
            );
        }

        return equal;
    }

    return false;
}

template <typename Data>
inline bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr<Data>& ht) const noexcept{
    return !(*this == ht);
}

template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& dat){
    unsigned long key = HashKey(hash(dat));
    if (table[key].Insert(dat)){
        ++size;
        return true;
    }

    return false;
}

template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& dat){
    unsigned long key = HashKey(hash(dat));
    if(table[key].Insert(std::move(dat))) {
        ++size;
        return true;
    }

    return false;
}

template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& dat) {
    unsigned long key = HashKey(hash(dat));
    if(table[key].Remove(dat)) {
        --size;
        return true;
    }

    return false;
}

template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& dat) const noexcept {
    return table[HashKey(dat)].Exists(dat);
}

template <typename Data>
void HashTableClsAdr<Data>::Resize(const unsigned long newsize) {
    if (newsize == 0){
        Clear();
    }
    
    HashTableClsAdr* tmp = new HashTableClsAdr(newsize);
    
    for (unsigned long i = 0; i < tableSize; ++i){
        table[i].Map(
            [tmp](Data& dat){
                tmp->Insert(std::move(dat));
            }
        );
    }

    std::swap(*tmp, *this);
    delete tmp;
}

template <typename Data>
void HashTableClsAdr<Data>::Clear() {
    for (unsigned long i = 0; i < tableSize; ++i){
        table[i].Clear();
    }
    this->size = 0;
}

/* ************************************************************************** */

}
