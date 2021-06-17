#ifndef PAIR_H
#define PAIR_H

#include <iomanip>
#include <iostream>

using namespace std;

template <typename K, typename V>
struct Pair {
    K key;
    V value;

    /**
     * @brief creates a Pair with key and value if key and value are given or
     * creates an empty Pair with the default values of type key and values
     * @param k the key for Pair
     * @param v the value for Pair
     */
    Pair(const K& k = K(), const V& v = V()) : key(k), value(v) {
    }

    /**
     * @brief an insertion operator that prints Pair's key and value to console 
     * @param outs an ostream operator to print Pair
     * @param p the Pair to be printed
     */
    friend ostream& operator<<(ostream& outs, const Pair<K, V>& p) {
        outs << std::left << setw(15) << p.key << "\t" << setw(5)
             << "|" << right << p.value;
        return outs;
    }

    friend bool operator==(const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
        return (lhs.key == rhs.key);
    }

    friend bool operator<(const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
        return (lhs.key < rhs.key);
    }

    friend bool operator>(const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
        return (lhs.key > rhs.key);
    }

    friend bool operator<=(const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
        return (lhs.key <= rhs.key);
    }

    friend bool operator>=(const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
        return (lhs.key >= rhs.key);
    }

    friend Pair<K, V> operator+(const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
        assert(lhs.key == rhs.key && "operator +: lhs.key != rhs.key ");
        return (Pair(lhs.key, rhs.value));
    }
};

#endif  // PAIR_H
