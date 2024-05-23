#include "Renderer.h"

void Renderer::RenderGame(Player player) {
    DrawTextureRec(player.GetTexture(), player.GetPlayerModel(), player.GetPlayerPosition() , player.GetColor());
}

void Renderer::RenderMenu() {

}