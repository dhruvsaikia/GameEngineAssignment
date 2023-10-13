#include "Engine.h"
#include "RenderSystem.h"
#include "InputManager.h"
#include "AssetManager.h"
#include "SceneManager.h"
#include "Component.h"
#include "Entity.h"
#include "Object.h"
#include "Scene.h"
#include <iostream>

Engine::Engine() : renderSystem(nullptr), inputManager(nullptr), assetManager(nullptr), sceneManager(nullptr) {
    std::cout << "Engine Created" << std::endl;
}

Engine::~Engine() {
    Destroy();
    std::cout << "Engine Destroyed" << std::endl;
}

void Engine::Initialize() {
    Load("GameSettings.json");
    renderSystem = new RenderSystem();
    renderSystem->Initialize();

    inputManager = new InputManager();
    inputManager->Initialize();

    assetManager = new AssetManager();
    assetManager->Initialize();

    sceneManager = new SceneManager();
    sceneManager->Initialize();

    std::cout << "Engine Initialized" << std::endl;
}

void Engine::Destroy() {
    if (renderSystem) {
        delete renderSystem;
        renderSystem = nullptr;
    }

    if (inputManager) {
        delete inputManager;
        inputManager = nullptr;
    }

    if (assetManager) {
        delete assetManager;
        assetManager = nullptr;
    }

    if (sceneManager) {
        delete sceneManager;
        sceneManager = nullptr;
    }

    std::cout << "Engine Destroyed" << std::endl;
}

void Engine::GameLoop() {
        renderSystem->Update();
        inputManager->Update();
        assetManager->Update();
        sceneManager->Update();
}

void Engine::Load(const std::string& settingsFile) {
    std::cout << "Loading game settings from: " << settingsFile << std::endl;
}
