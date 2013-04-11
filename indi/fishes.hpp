#pragma once

#include <vector>
#include <thread>

#include <indi/scalars.hpp>
#include <indi/random.hpp>

namespace Indi {

class Fish {
private:
public:

    Time birth;
    Time death;

    Sex sex;
    Length length;

    Latitude lat;
    Longitude lon;

    Fish(void){
        //! @randomise initial attribute values
        birth = now;
        death = 0;
        sex = male;
        length = 0;
        lat = Latitude(0);
        lon = Longitude(0);
    }

    Fish& survive(void){
        //! @todo probabalistic mortality with given rate
        //death = now;
        distribution(random);
        return *this;
    }

    Fish& grow(void){
        //! @todo implement real growth curve with random
        //variation
        Length incr = Length(10)-0.1*length + distribution(random);
        length += incr;
        return *this;
    }

    Fish& move(void){
        //! @todo implement movement in respone to Environs
        lat += distribution(random)*2 - 1;
        lon += distribution(random)*2 - 4;
        return *this;
    }

    template<class Environs>
    Fish& update(const Environs& environs){
        survive();
        grow();
        move();
        return *this;
    }

}; //end class Fish

template<
    typename Fish = Indi::Fish
>
class Fishes : public std::vector<Fish> {
private:
    typedef std::vector<Fish> Base;

public:

    unsigned int start_number;

    template<class Environs>
    void start(const Environs& environs){
        Base::clear();
        Base::resize(start_number);
    }

    #ifndef FISHES_PARALLEL

    template<class Environs>
    void update(const Environs& environs){
        for(Fish& fish : *this){
            fish.update(environs);
        }
    }

    #else

    template<class Environs>
    static void update_task(Fishes& fishes, const Environs& environs, const unsigned int& start, const unsigned int& num){
        auto fish = fishes.begin()+start;
        auto end = fish+num;
        while(fish!=end){
            fish->update(environs);
            fish++;
        }
    }

    template<class Environs>
    void update(const Environs& environs){
        int each = Base::size()/5;

        std::thread thread1(update_task<Environs>,*this,environs,0,each);
        std::thread thread2(update_task<Environs>,*this,environs,each,each);
        std::thread thread3(update_task<Environs>,*this,environs,each*2,each);
        std::thread thread4(update_task<Environs>,*this,environs,each*3,each);
        std::thread thread5(update_task<Environs>,*this,environs,each*4,each);

        thread1.join();
        thread2.join();
        thread3.join();
        thread4.join();
        thread5.join();
    }

    #endif

};
    
} // end namespace Indi

