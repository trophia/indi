#pragma once

#include <indi/indi.hpp>

namespace IoSkipjack {

class Model : public Indi::Model<> {
public:

	Model(void){

		fishes.start_number = 1000;

		vessels.start_number = 100;

	}

};

} //namespace IoSkipjack
