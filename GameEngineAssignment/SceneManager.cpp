#include "SceneManager.h"
#include "Scene.h" // Include the Scene class header
#include <iostream> // Include the necessary header for console output

SceneManager::SceneManager() {
    // Constructor
    std::cout << "SceneManager Created" << std::endl;
}

SceneManager::~SceneManager() {
    // Destructor
    Destroy();
    std::cout << "SceneManager Destroyed" << std::endl;
}

void SceneManager::Initialize() {
    // Initialize the scene manager, set up scenes, etc.
    std::cout << "SceneManager Initialized" << std::endl;
}

void SceneManager::Destroy() {
    // Cleanup resources, release scenes, etc.
    std::cout << "SceneManager Destroyed" << std::endl;
}

void SceneManager::Update() {
    // Handle scene updates and transitions
}

void SceneManager::AddScene(Scene* scene) {
    // Add a scene to the scene manager
}

void SceneManager::RemoveScene(Scene* scene) {
    // Remove a scene from the scene manager
}
