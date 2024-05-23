#include "Renderer.h"

void Renderer::Render(Player player) {
    DrawRectangleRec(player.GetPlayerModel(), player.GetColor());
}