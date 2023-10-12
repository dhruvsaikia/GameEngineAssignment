#include "Scene.h"
#include "Entity.h" // Include the Entity class header
#include <iostream> // Include the necessary header for console output

Scene::Scene() {
    // Constructor
    std::cout << "Scene Created" << std::endl;
}

Scene::~Scene() {
    // Destructor
    Destroy();
    std::cout << "Scene Destroyed" << std::endl;
}

void Scene::Initialize() {
    // Initialize the scene, set up entities, etc.
    std::cout << "Scene Initialized" << std::endl;
}

void Scene::Destroy() {
    // Cleanup resources, release entities, etc.
    std::cout << "Scene Destroyed" << std::endl;
}

void Scene::Update() {
    // Handle scene-specific updates
}

void Scene::Load(const std::string& sceneSettingsFile) {
    // Load scene-specific data from the provided JSON file (e.g., "SceneSettings.json")
    // Parse the JSON data and extract necessary information
    // For example, you can use a JSON library like "nlohmann/json" for this
    std::cout << "Loading scene settings from: " << sceneSettingsFile << std::endl;
}

void Scene::AddEntity(Entity* entity) {
    // Add an entity to the scene
}

void Scene::RemoveEntity(Entity* entity) {
    // Remove an entity from the scene
}
