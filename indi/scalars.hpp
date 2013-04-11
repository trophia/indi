#pragma once

#include <cmath>

#include <indi/scalar.hpp>

namespace Indi {

typedef Scalar<0,unsigned short> Time;
template<> float Time::base = 0;
template<> float Time::incr = 1;

Time now;

typedef Scalar<1,unsigned short> Latitude;
template<> float Latitude::base = -90;
template<> float Latitude::incr = 180/(std::pow(2,sizeof(short)*8));

typedef Scalar<2,unsigned short> Longitude;
template<> float Longitude::base = 0;
template<> float Longitude::incr = 360/(std::pow(2,sizeof(short)*8));

enum Sex {
	male = 1,
	female = 2
};
	
typedef Scalar<3,unsigned short> Length;
template<> float Length::base = 0;
template<> float Length::incr = 0.001;

} //end namespace Indi
