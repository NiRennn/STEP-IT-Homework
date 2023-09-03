#include "Transport.h"

class Plane : public Transport
{
private:
	uint16_t* wingspan = new uint16_t{};
public:
	Plane(char*, char*, char*, uint16_t&, uint16_t&, uint16_t&);

	friend std::ostream& operator <<(std::ostream& os, const Plane other)
	{
		os
			<< "Plane mark: " << other.mark << std::endl
			<< "Plane model: " << other.model << std::endl
			<< "Plane fuel type: " << other.fuelType << std::endl
			<< "Plane seats: " << *other.seats << std::endl
			<< "Plane max speed: " << *other.maxSpeed << std::endl
			<< "Plane wingspan " << other.wingspan << std::endl;
		return os;
	}

	bool operator == (const Plane other)
	{
		return this->mark == other.mark && this->model == other.model && this->fuelType == other.fuelType &&
			this->seats == other.seats && this->maxSpeed == other.maxSpeed && this->wingspan == other.wingspan;
	}

	bool operator !=(const Plane other)
	{
		return !(*this == other);
	}

	uint16_t getWingspan() const;

	~Plane() override;
};