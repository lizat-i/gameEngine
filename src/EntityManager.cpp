#include "EntityManager.hpp"

std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag)
{
    auto e = std::make_shared<Entity>(tag, m_totalEntities++);
    m_toAdd.push_back(e);
    return e;
}
void EntityManager::update()
{
    for (auto e : m_toAdd)
    {

        m_Entities.push_back(e);
        m_entityMap[e->tag()].push_back(e);
    }
    m_toAdd.clear();

    m_Entities.erase(
        std::remove_if(
            m_Entities.begin(),
            m_Entities.end(),
            [](const std::shared_ptr<Entity> &entity)
            {
                return !entity->isAlive();
            }),
        m_Entities.end());

    for (auto &mapEntry : m_entityMap)
    {
        auto &vec = mapEntry.second; // Reference to the vector
        vec.erase(
            std::remove_if(
                vec.begin(),
                vec.end(),
                [](const std::shared_ptr<Entity> &entity)
                {
                    return !entity->isAlive(); // Condition to remove the entity
                }),
            vec.end());
    }
}