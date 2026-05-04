

#include "TgaImage.h"



int main (){


    //delcare and init a image in tga image namespace ti
    ti::TgaImage boxpic(ti::TgaImage(128,128));


    // delcare and init a new collor
    auto uglycolor(ti::Color(30,140,120));

    //fill the image with your color
    boxpic.fill(uglycolor);

    boxpic.save("boxpic.tga");


    return 0;
};