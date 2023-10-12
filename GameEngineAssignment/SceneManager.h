#pragma once

#include <list>

class Scene; // Forward declaration of the Scene class

class SceneManager {
public:
    SceneManager();
    ~SceneManager();

    void Initialize();
    void Destroy();
    void Update();

    void AddScene(Scene* scene);
    void RemoveScene(Scene* scene);
    void Load();
};
