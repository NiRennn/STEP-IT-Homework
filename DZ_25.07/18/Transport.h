#include <iostream>
#include <regex>

class Transport
{
protected:
	char* mark = new char[20]{};
	char* model = new char[20]{};
	char* fuelType = new char[20]{};
	uint16_t* seats = new uint16_t{};
	uint16_t* maxSpeed = new uint16_t{};
public:
	Transport(char*, char*, char*, uint16_t&, uint16_t&);

	char* getMark() const;
	char* getModel() const;
	char* getfuelType() const;
	uint16_t getSeats() const;
	uint16_t getMaxSpeed() const;

	virtual ~Transport() = 0;
};