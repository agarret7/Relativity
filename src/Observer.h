/*
 * Observer.h
 *
 *  Created on: Dec 30, 2016
 *      Author: agarret7
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <armadillo>

using namespace arma;

class Observer {
public:
	Observer(vec);
	void boost(vec);
	void accelerate(vec);
	vec getVelocity() {return velocity;}

private:
	vec velocity;
};

#endif /* OBSERVER_H_ */
