#pragma once

#include <list>

namespace Indi {

class Vessel {
private:
public:
    void update(void){
    }
}; //end class Vessel

template<
	typename Vessel = Indi::Vessel
>
class Vessels : public std::list<Vessel> {
private:
public:
	template<
		class Environs,
		class Fishes
	>
    void update(const Environs& environs,const Fishes& fishes){
    }
}; //end class Vessels
	
} // end namespace Indi
