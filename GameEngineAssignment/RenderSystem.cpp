#include "RenderSystem.h"
#include <iostream>
#include "json.hpp"
#include <fstream>

RenderSystem::RenderSystem() : name("Default"), width(1280), height(720), fullscreen(false) {
 
}

RenderSystem::~RenderSystem() {
    std::cout << "RenderSystem Destructor" << std::endl;
}

void RenderSystem::Initialize() {
    std::cout << "RenderSystem Default Initialization" << std::endl;
}

void RenderSystem::Initialize(json::JSON& document) {
    Load(document);
}

void RenderSystem::Destroy() {
    std::cout << "RenderSystem Destroyed" << std::endl;
}

void RenderSystem::Update() {
    std::cout << "RenderSystem Update" << std::endl;
}

void RenderSystem::Load(json::JSON& document) {
    if (document.hasKey("RenderSystem")) {
        json::JSON renderSettings = document["RenderSystem"];

        if (renderSettings.hasKey("Name")) {
            name = renderSettings["Name"].ToString();
        }

        if (renderSettings.hasKey("width")) {
            width = renderSettings["width"].ToInt();
        }

        if (renderSettings.hasKey("height")) {
            height = renderSettings["height"].ToInt();
        }

        if (renderSettings.hasKey("fullscreen")) {
            fullscreen = renderSettings["fullscreen"].ToBool();
        }

        std::cout << "RenderSystem Initialized with settings: "
            << "Name: " << name << ", "
            << "Width: " << width << ", "
            << "Height: " << height << ", "
            << "Fullscreen: " << (fullscreen ? "True" : "False")
            << std::endl;
    }
    else {
        std::cerr << "Error: 'RenderSystem' key not found in the JSON data." << std::endl;
    }
}
