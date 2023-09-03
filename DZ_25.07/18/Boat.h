#include "Transport.h"

class Boat : public Transport	
{
private:
	char* keelType = new char[20] {};
public:
	Boat(char*, char*, char*, char*, uint16_t&, uint16_t&);

	friend std::ostream& operator <<(std::ostream& os, const Boat other)
	{
		os
			<< "Boat mark: " << other.mark << std::endl
			<< "Boat model: " << other.model << std::endl
			<< "Boat fuel type: " << other.fuelType << std::endl
			<< "Boat seats: " << *other.seats << std::endl
			<< "Boat max speed: " << *other.maxSpeed << std::endl
			<< "Boat keel type: " << other.keelType << std::endl;
		return os;
	}

	bool operator == (const Boat other)
	{
		return this->mark == other.mark && this->model == other.model && this->fuelType == other.fuelType &&
			this->seats == other.seats && this->maxSpeed == other.maxSpeed && this->keelType == other.keelType;
	}

	bool operator !=(const Boat other)
	{
		return !(*this == other);
	}

	char* getKellType() const;

	~Boat() override;
};

