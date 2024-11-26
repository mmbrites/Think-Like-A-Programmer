#pragma once

template <typename K, typename V>
class Pair {

    public:
        // CONSTRUCTORS
        Pair();
        Pair(K key, V value);

        // GETTERS AND SETTERS
        K key();
        void setKey(K key);
        V value() const;
        void setValue(V value);
        bool initialised() const;

    private:
        K _key;
        V _value;
        bool _initialised;

};

// Implementation of template methods (must be in header file)

template<typename K, typename V>
Pair<K, V>::Pair() : _initialised(false) { }

template<typename K, typename V>
Pair<K, V>::Pair(K key, V value) : _key(key), _value(value), _initialised(true) { }

template<typename K, typename V>
K Pair<K, V>::key() {
    return _key;
}

template<typename K, typename V>
void Pair<K, V>::setKey(K key) {
    _key = key;
}

template<typename K, typename V>
V Pair<K, V>::value() const {
    return _value;
}

template<typename K, typename V>
void Pair<K, V>::setValue(V value) {
    _value = value;
}

template<typename K, typename V>
bool Pair<K, V>::initialised() const {
    return _initialised;
}