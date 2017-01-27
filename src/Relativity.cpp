//============================================================================
// Name        : Relativity.cpp
// Author      : Austin Garrett, Tuan Nguyen
// Version     :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Observer.h"

#include <iostream>
#include <armadillo>
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace arma;
using namespace sf;

vec lorentzBoost(vec,vec);
double spacetimeInvariant(vec,vec);

// We choose an arbitrary rest frame to do our calculations.
// In the future we should choose the obser2ver to be the rest frame.
// Each object is described by a 4-position and 4-velocity.
// Each observer has a list of velocity magnitudes that
// Each observer

int main() {
    RenderWindow window(VideoMode(200, 200), "SFML works!");
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

vec lorentzBoost(vec X, vec v) {
	double vNorm = norm(v);
	double gamma = 1 / sqrt(1 - pow(vNorm, 2));
	vec n = v / vNorm;

	mat L = {{gamma, -gamma*v[0], -gamma*v[1], -gamma*v[2]},
			{-gamma*v[0], 1 + (gamma-1)*n[0]*n[0], (gamma-1)*n[0]*n[1], (gamma-1)*n[0]*n[2]},
			{-gamma*v[1], (gamma-1)*n[1]*n[0], 1 + (gamma-1)*n[1]*n[1], (gamma-1)*n[1]*n[2]},
			{-gamma*v[2], (gamma-1)*n[2]*n[0], (gamma-1)*n[2]*n[1], 1 + (gamma-1)*n[2]*n[2]}};

	return vec(L * X);
}

double spacetimeInvariant(vec v1, vec v2) {
	vec delta = v2 - v1;
	vec deltaSquared = delta.transform([=](double x) -> int { return pow(x,2); });

	return -deltaSquared[0] + deltaSquared[1] + deltaSquared[2] + deltaSquared[3];
}
