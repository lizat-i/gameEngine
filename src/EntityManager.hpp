#include "Entity.hpp"
#include <map>

typedef std::vector <std::shared_ptr<Entity>> EntityVec;
typedef std::map    <std::string , EntityVec> EntityMap;

class EntityManager
{
private:
    /* data */
    EntityVec m_Entities;
    EntityVec m_toAdd;
    EntityMap m_entityMap;
    size_t m_totalEntities=0;


public:
    EntityManager() = default;
    ~EntityManager() = default;
    std::shared_ptr<Entity> addEntity(const std::string& tag);
    EntityVec& getEntity();
    EntityVec& getEntity(const std::string&  tag);
    void update();
    
};

