#pragma once

#include <iostream>

#include <indi/fishes.hpp>
#include <indi/vessels.hpp>
#include <indi/environs.hpp>

namespace Indi {

template <
	class Fishes = Indi::Fishes<>,
	class Vessels = Indi::Vessels<>,
	class Environs = Indi::Environs
> 
class Model {
protected:

	Fishes fishes;
	Vessels vessels;
	Environs environs;

public:

	void start(void){
		environs.start();
		fishes.start(environs);
		vessels.start(fishes,environs);
	}

	void step(const int& steps=1){
		for(int step=0;step<steps;step++){
			std::cout<<step<<std::endl;
			environs.update();
			fishes.update(environs);
			vessels.update(fishes,environs);
		}
	}

	void stop(void){
	}

	int main(int argc, char **argv){
		start();
		step(1000);
		stop();
		return 0;
	}

}; //end class Model
	
} // end namespace Indi
