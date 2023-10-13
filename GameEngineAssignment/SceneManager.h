#pragma once

#include <list>

class Scene;

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
