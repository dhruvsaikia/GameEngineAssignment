#pragma once

#include <list>
#include "Scene.h"
#include "json.hpp" 

class SceneManager {
public:
    SceneManager();
    ~SceneManager();

    void Initialize();
    void Destroy();
    void Update();

    void AddScene(Scene* scene);
    void RemoveScene(Scene* scene);

    void LoadScenes(json::JSON& document);

private:
    std::list<Scene*> scenes;
};