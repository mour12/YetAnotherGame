#include "game_entity.hpp"
#include "ray2d.hpp"
#include "bullet.hpp"

class Gun : public GameEntity
{
public:
  Gun(Gun const & obj);
  Gun(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePrt);
  ~Gun() override {}
  void ToString(std::ostream & os) const override;

  Gun & operator=(Gun const & obj);

  bool operator==(Gun const & obj) const;
  bool operator!=(Gun const & obj) const;

  void Shoot();
};
