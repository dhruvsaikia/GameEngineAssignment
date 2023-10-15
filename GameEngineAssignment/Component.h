#pragma once
#include "json.hpp"

class Component {
public:
    Component(int id);
    ~Component();

    void Initialize();
    void Destroy();
    void Update();
    int GetComponentId() const;
    void Load(json::JSON& componentData);

private:
    int id;
};
