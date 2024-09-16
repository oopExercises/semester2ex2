#include "IdValidator.h"

bool IdValidator::checkValidation(const uint32_t& id) const
{

    std::string idStr = std::to_string(id);
    if (idStr.size() != 9)
        return false;

    int sum = 0;
    for (int i = 0; i < 9; i++) {
        int digit = idStr[i] - '0';
        if (i % 2 == 0) {
            digit *= 1;
        }
        else {
            digit *= 2;
            if (digit > 9) {
                digit = digit / 10 + digit % 10;
            }
        }
        sum += digit;
    }
    return sum % 10 == 0;
}

std::string IdValidator::getErrorMessage() const
{
	return "Wrong control digit";
}
