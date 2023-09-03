#include "Car.h"

Car::Car(char* _mark, char* _model, char* _fuelType, char* _bodytype, uint16_t& _seats, uint16_t& _maxSpeed) : Transport(_mark,
	_model, _fuelType, _seats, _maxSpeed)
{
	this->bodyType = _bodytype;
}

char* Car::getBodyType() const
{
	return this->bodyType;
}

Car::~Car()
{
	delete[] this->mark;
	delete[] this->model;
	delete[] this->fuelType;
	delete this->seats;
	delete this->maxSpeed;
	delete[] this->bodyType;
}