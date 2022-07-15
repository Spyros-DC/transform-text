#include "number.h"
#include <ostream>

using namespace words::numbers;

std::ostream& operator<<(std::ostream& os, const order& ord);

std::ostream& operator<<(std::ostream& os, const word& w);

std::ostream& operator<<(std::ostream& os, const number& num);