#ifndef FDEBD653_9116_4DA8_92C6_72B1C6C521DD
#define FDEBD653_9116_4DA8_92C6_72B1C6C521DD
#include "PersistanceData.hpp"

class DataValidator
{

public:
    static bool validateData(NVData_t data)
    {
        return (strcmp(data.Header.validation, VALID_STRING) == 0 && data.Header.NVDataSize == sizeof(data));
    }
};

#endif /* FDEBD653_9116_4DA8_92C6_72B1C6C521DD */
