
#include "gun.hpp"

#ifndef AWP__
#define AWP__

class AWP : public Gun {
public:

	AWP();
	~AWP();

	std::string GetGunName() const override;
};

#endif