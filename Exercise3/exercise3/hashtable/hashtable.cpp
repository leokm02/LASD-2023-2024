
namespace lasd {

/* ************************************************************************** */

template <>
class Hashable<int> {
public:
    unsigned long operator()(const int& dat) const noexcept {
        return (dat * dat);
    }
};

template <>
class Hashable<double> {
public:
    unsigned long operator()(const double& dat) const noexcept {

        long intPart = floor(dat);
        long fracPart = pow(2, 24) * (dat - intPart);

        return (intPart * fracPart);
    }
};

template <>
class Hashable<std::string> {
public:
    unsigned long operator()(const std::string& dat) const noexcept {
        unsigned long hsh = 5381;
        for (unsigned long i = 0; i < dat.length(); ++i){
            hsh = (hsh << 5) + dat[i];
        }

        return hsh;
    }
};




template <typename Data>
HashTable<Data>::HashTable(){
    a = distA(gen);
    b = distB(gen);
}

template <typename Data>
HashTable<Data>::HashTable(const HashTable<Data>& ht){
    size = ht.size;
    a = ht.a;
    b = ht.b;
    tableSize = ht.tableSize;
}

template <typename Data>
HashTable<Data>::HashTable(HashTable<Data>&& ht) noexcept {
    std::swap(size, ht.size);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(tableSize, ht.tableSize);
}

template <typename Data>
HashTable<Data>& HashTable<Data>::operator=(const HashTable<Data>& ht){
    size = ht.size;
    a = ht.a;
    b = ht.b;
    tableSize = ht.tableSize;

    return *this;
}

template <typename Data>
HashTable<Data>& HashTable<Data>::operator=(HashTable<Data>&& ht) noexcept{
    std::swap(size, ht.size);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(tableSize, ht.tableSize);

    return *this;
}

template <typename Data>
unsigned long HashTable<Data>::HashKey(const Data& dat) const noexcept{
    return HashKey(hash(dat));
}

template <typename Data>
unsigned long HashTable<Data>::HashKey(const unsigned long key) const noexcept{
    return (((a*key+b) % p) % tableSize);
}

/* ************************************************************************** */

}
