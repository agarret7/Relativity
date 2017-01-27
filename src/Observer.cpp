/*
 * Observer.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: agarret7
 */

#include "Observer.h"

Observer::Observer(vec velocity) :
	velocity(velocity) {}

void Observer::boost(vec dv) {
	// Boosts the observer a relative velocity dv.
	// This would generate constant 3 acceleration in the MCRF of the observer.
	double gamma = 1 / sqrt(1 - pow(norm(dv), 2));
	velocity = 1 / (1 + dot(velocity,dv))
			* (velocity + dv/gamma + gamma/(1 + gamma)
			* dot(velocity, dv) * dv);
}

void Observer::accelerate(vec direction) {

}
