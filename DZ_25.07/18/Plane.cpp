#include "Plane.h"

Plane::Plane(char* _mark, char* _model, char* _fuelType, uint16_t& _seats, uint16_t& _maxSpeed, uint16_t& _wingspan) : Transport(_mark,
	_model, _fuelType, _seats, _maxSpeed)
{
	*this->wingspan = _wingspan;
}

uint16_t Plane::getWingspan() const
{
	return *this->wingspan;
}

Plane::~Plane()
{
	delete[] this->mark;
	delete[] this->model;
	delete[] this->fuelType;
	delete this->seats;
	delete this->maxSpeed;
	delete this->wingspan;
}