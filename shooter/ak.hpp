
#include "gun.hpp"

#ifndef AK_
#define AK_

class AK : public Gun {
public:

	AK();
	~AK();

	std::string GetGunName() const override;

};

#endif