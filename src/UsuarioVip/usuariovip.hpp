#include "../Usuarios/DataModel/usuario.hpp"

class usuariovip: public usuario
{
  public:
    
    virtual double desconto_multa(double &multa) override;
};


