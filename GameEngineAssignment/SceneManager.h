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

    void Load(json::JSON& document);
    const std::list<Scene*>& GetScenes() const { return scenes; }
private:
    std::list<Scene*> scenes;
};