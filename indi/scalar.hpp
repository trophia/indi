#pragma once

namespace Indi {
	
template<
    int Code,
    typename Type
>
class Scalar {
private:
    Type value;

public:
    static float base;
    static float incr;
    
    Scalar(void):
        value(0){
    }

    Scalar(float real):
        value((real-base)/incr){
    }
    
    operator float(void) const {
        return base+value*incr;
    }
    
    bool operator<(const Scalar& other) const {
        return value<other.value;
    }

    bool operator>(const Scalar& other) const {
        return value>other.value;
    }
    
    Scalar& operator++(int){
        value++;
        return *this;
    }
    
    void operator+=(const Scalar& other){
        value += other.value;
    }

    void operator-=(const Scalar& other){
        value -= other.value;
    }

    void operator*=(const Scalar& other){
        value *= other.value;
    }

    void operator/=(const Scalar& other){
        value /= other.value;
    }
};

} //end namespace Indi
