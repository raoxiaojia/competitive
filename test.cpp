#include <unordered_set>

typedef int T;

template <class T>
class iterator2
{
public:
    std::unordered_multiset<T> toBeSkipped;
    T next(){
        
    }
    bool hasNext(){}
    void skip(T value) {
        toBeSkipped.insert(value);
    }
    T newNext(T default){
        T value = default;
        while (hasNext()) {
            T value = next();
            if (toBeSkipped.find(value) == toBeSkipped.end()) {
                break;
            }
            toBeSkipped.erase(iterator);
        }
        return value;
    }
};