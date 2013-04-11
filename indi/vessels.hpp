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
    typedef std::list<Vessel> List;

public:

    unsigned int start_number;

    template<
        class Environs,
        class Fishes
    >
    void start(const Environs& environs,const Fishes& fishes){
        List::clear();
        List::resize(start_number);
    }

    template<
        class Environs,
        class Fishes
    >
    void update(const Environs& environs,const Fishes& fishes){
        for(Vessel& vessel : *this){
            vessel.update();
        }
    }
}; //end class Vessels
    
} // end namespace Indi
