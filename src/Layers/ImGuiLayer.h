#pragma once

#include "Layer.h"

namespace Engine {

class ImGuiLayer : public Layer
{
public:
    void onAttach() override;
    void onUpdate() override;
    void onDetach() override;
};

} // namespace Engine
