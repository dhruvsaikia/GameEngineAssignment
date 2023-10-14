#pragma once
#include "RenderSystem.h"
#include "InputManager.h"
#include "AssetManager.h"
#include "SceneManager.h"
#include "json.hpp"
#include <string>

class Engine {
public:
    Engine();
    ~Engine();

    void Initialize();
    void Destroy();
    void GameLoop();
    void Load(const std::string& settingsFile);

private:
    RenderSystem* renderSystem;
    InputManager* inputManager;
    AssetManager* assetManager;
    SceneManager* sceneManager;
    json::JSON jsonData;
};