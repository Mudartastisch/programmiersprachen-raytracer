#pragma once
#include <glm/vec3.hpp>
#include "color.hpp"
class Shape
{
public:
	Shape();
	~Shape();
	virtual float area() const;
	virtual float volume() const;
	//virtual std::ostream & print(std::ostream & os) const; 
	//std::ostream& operator<<(std::ostream& os, Shape const & s)
};


