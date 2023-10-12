#pragma once

class Component {
public:
    Component(int id);
    ~Component();

    void Initialize();
    void Destroy();
    void Update();
    int GetComponentId() const;

private:
    int id; // Member variable to store the component's ID
};
