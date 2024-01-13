#include <string>
#include <vector>
#include <memory>
#include "Components.hpp"

class Entity
{
private:
    /* data */
    const size_t m_ID = 0;
    const std::string m_type = "default";
    bool m_alive = true; 

public:

    Entity(/* args */)= default;
    Entity(const std::string & tag, const size_t id):
       m_type(tag), m_ID(id){};

    ~Entity() = default;

    std::vector<std::shared_ptr<Components>> m_Components;

    const void addCompontent(const std::shared_ptr<Components> inputComponent){
        m_Components.push_back(inputComponent);
    };
    const std::string tag() const {
        return m_type;
    };
    const bool isAlive(){
        return m_alive;
    };
    
    // void destroy(){};
};