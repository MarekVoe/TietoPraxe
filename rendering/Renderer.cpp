#include "Renderer.h"

void Renderer::Render(Player player) {
    DrawTextureRec(player.GetTexture(), player.GetPlayerModel(), player.GetPlayerPosition() , player.GetColor());
}