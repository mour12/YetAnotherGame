#include "game_entity.hpp"
#include "ray2d.hpp"
#include "bullet.hpp"

class Alien : public GameEntity
{
public:
  Alien(Alien const & obj);
  Alien(Box2D const & box, Direction2D const & direction, float velocity, int health, Ray2D const & route, std::weak_ptr<Space> const spacePrt);
  ~Alien() override {}
  void serialize(std::ostream & os) const override;

  Alien & operator=(Alien const & obj);

  bool operator==(Alien const & obj) const;
  bool operator!=(Alien const & obj) const;

  Ray2D & route();

  Ray2D const & route() const;

  void Shoot();

protected:
  Ray2D m_route;
};
