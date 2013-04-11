#pragma once

#include <list>

namespace Indi {

class Fish {
private:
public:
    void update(void){
    }
}; //end class Fish

template<
	typename Fish = Indi::Fish
>
class Fishes : public std::list<Fish> {
private:
public:
	template<class Environs>
    void update(const Environs& environs){
    }
};
	
} // end namespace Indi

