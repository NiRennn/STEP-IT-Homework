#include "Boat.h"

Boat::Boat(char* _mark, char* _model, char* _fuelType, char* _Keeltype, uint16_t& _seats, uint16_t& _maxSpeed) : Transport(_mark, 
	_model, _fuelType, _seats, _maxSpeed)
{
	this->keelType = _Keeltype;
}

char* Boat::getKellType() const
{
	return this->keelType;
}

Boat::~Boat() 
{
	delete[] this->mark;
	delete[] this->model;
	delete[] this->fuelType;
	delete this->seats;
	delete this->maxSpeed;
	delete[] keelType;
}