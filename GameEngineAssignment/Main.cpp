#include "Engine.h" 

int main() {
    Engine engine;
    engine.Initialize();
    engine.GameLoop();
    engine.Destroy();  
    return 0;
}