#pragma once

namespace Engine {

class Layer
{
public:
    Layer() = default;
    virtual ~Layer() = default;

public:
    virtual void onAttach() = 0;
    virtual void onUpdate() = 0;
    virtual void onDetach() = 0;
    inline bool isEnabled() const { return m_enabled; }
    inline void toggle(bool active) { m_enabled = active; }

protected:
    bool m_enabled = true;
};

} // namespace Engine
