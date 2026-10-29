#pragma once

// Base class for all scenes (Winter, Spring, Summer, Autumn)
class Scene {
public:
    virtual ~Scene() {}        // Nvirtual destructor (safe deletion through a Scene pointer)
    virtual void draw() = 0;   // every scene must define its own draw()
};