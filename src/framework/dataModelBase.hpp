#include <iostream>

#ifndef DATAMODELBASE_HEADER
#define DATAMODELBASE_HEADER

class DataModelBase
{
private:
public:
    virtual void set_atributo(std::string atributo, std::string value) = 0;

    // TO_STRING
    virtual std::string to_string() = 0;
};

#endif // DATAMODELBASE_HEADER