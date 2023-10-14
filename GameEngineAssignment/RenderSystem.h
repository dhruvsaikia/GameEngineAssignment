#pragma once

#include <string>
#include "json.hpp"

class RenderSystem {
public:
    RenderSystem();
    ~RenderSystem();

    void Initialize();
    void Destroy();
    void Update();
    void Initialize(json::JSON& document);
    void Load(json::JSON& document);

private:
    std::string name;
    int width;
    int height;
    bool fullscreen;
};
