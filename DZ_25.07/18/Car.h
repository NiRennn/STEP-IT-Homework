#include "Transport.h"

class Car : public Transport
{
private:
	char* bodyType = new char[20] {};
public:
	Car(char*, char*, char*, char*, uint16_t&, uint16_t&);


	friend std::ostream& operator <<(std::ostream& os, const Car other)
	{
		os
			<< "Car mark: " << other.mark << std::endl
			<< "Car model: " << other.model << std::endl
			<< "Car fuel type: " << other.fuelType << std::endl
			<< "Car seats: " << *other.seats << std::endl
			<< "Car max speed: " << *other.maxSpeed << std::endl
			<< "Car body type: " << other.bodyType << std::endl;
		return os;
	}

	bool operator == (const Car other)
	{
		return this->mark == other.mark && this->model == other.model && this->fuelType == other.fuelType &&
			this->seats == other.seats && this->maxSpeed == other.maxSpeed && this->bodyType == other.bodyType;
	}

	bool operator !=(const Car other)
	{
		return !(*this == other);
	}

	char* getBodyType() const;

	~Car() override;
};