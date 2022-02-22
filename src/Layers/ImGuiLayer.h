#pragma once

#include "Layer.h"

namespace Engine {

class ImGuiLayer : public Layer
{
public:
    void onAttach() override;
    void runImGui();
    void onUpdate(double frameTime) override;
    void endImGui();
    void onDetach() override;

private:
    void showStats(double frameTime);
};

} // namespace Engine
