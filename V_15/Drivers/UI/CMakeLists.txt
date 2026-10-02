SET(SOURCES components/ui_comp_slider2.c
    components/ui_comp.c
    screens/ui_Screen1.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_2077717688.c
    images/ui_img_ffff_png.c
    images/ui_img_582887121.c)

add_library(ui ${SOURCES})
