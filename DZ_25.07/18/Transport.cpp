#include "Transport.h"

Transport::Transport(char* _mark, char* _model, char* _fuelType, uint16_t& _seats, uint16_t& _maxSpeed)
{
	std::regex regexMarkandFuelType("[a-zA-Z]{3,10}");
	std::regex regexModel("[a-zA-Z0-9]{3,10}");

	if (!std::regex_match(_mark, regexMarkandFuelType)) {
		throw std::invalid_argument("Invalid mark");
	}
	if (!std::regex_match(_model, regexModel)) {
		throw std::invalid_argument("Invalid model");
	}
	if (!std::regex_match(_fuelType, regexMarkandFuelType)) {
		throw std::invalid_argument("Invalid fuel type");
	}
	this->mark = _mark;
	this->model = _model;
	this->fuelType = _fuelType;
	*this->seats = _seats;
	*this->maxSpeed = _maxSpeed;
}

char* Transport::getMark() const
{
	return this->mark;
}

char* Transport::getModel() const
{
	return this->model;
}

char* Transport::getfuelType() const
{
	return this->fuelType;
}

uint16_t Transport::getSeats() const
{
	return *this->seats;
}

uint16_t Transport::getMaxSpeed() const
{
	return *this->maxSpeed;
}
