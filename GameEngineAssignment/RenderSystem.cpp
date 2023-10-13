#include "RenderSystem.h"
#include <iostream> 

RenderSystem::RenderSystem() : name("Default"), width(1280), height(720), fullscreen(false) {
    std::cout << "RenderSystem Created" << std::endl;
}

RenderSystem::~RenderSystem() {
    Destroy();
    std::cout << "RenderSystem Destroyed" << std::endl;
}

void RenderSystem::Initialize() {
    Load("RenderSettings.json");
    std::cout << "RenderSystem Initialized" << std::endl;
}

void RenderSystem::Destroy() {
    std::cout << "RenderSystem Destroyed" << std::endl;
}

void RenderSystem::Update() {
}

void RenderSystem::Load(const std::string& renderSettingsFile) {
    std::cout << "Loading render settings from: " << renderSettingsFile << std::endl;
}
