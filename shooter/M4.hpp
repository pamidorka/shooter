
#include "gun.hpp"

#ifndef M4__
#define M4__

class M4 : public Gun {
public:

	M4();
	~M4();

	std::string GetGunName() const override;
};

#endif