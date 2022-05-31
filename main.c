#include <gb/gb.h>
#include "src/char.c"
#include "src/background.c"
#include "src/bg_tiles.c"
#include <stdio.h>

void main(){
    // printf("Hello World!");
    // Sprites
    set_sprite_data(0, 2, Smiler); // loads sprites into memory
    set_sprite_tile(0, 0); // sets first sprite
    move_sprite(0, 88, 78); // moves sprite to xy position
    SHOW_SPRITES;

    // backgrounds
    set_bkg_data(0, 7, bgTiles); // loads bg tiles to memory
    set_bkg_tiles(0, 0, 40, 18, background);

    SHOW_BKG;
    DISPLAY_ON;

    // gameloop
    while (1)
    {
        switch (joypad())
        {
        case J_LEFT:
            // scroll_sprite(0, -10, 0);
            scroll_bkg(-10, 0);
            break;
        case J_RIGHT:
            // scroll_sprite(0, 10, 0);
            scroll_bkg(10, 0);
            break;
        case J_UP:
            // scroll_sprite(0, 0, -10);
            scroll_bkg(0, -10);
            break;
        case J_DOWN:
            // scroll_sprite(0, 0, 10);
            scroll_bkg(0, 10);
            break;
        default:
            break;
        }
        delay(100);
    }


}