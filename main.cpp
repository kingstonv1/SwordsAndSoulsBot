#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>

//Object to acess keyboard virually

class color
{
    public:
        
        struct RGBcolor
        {
            unsigned int R;
            unsigned int G;
            unsigned int B;
        
            auto operator<=>(const RGBcolor&) const = default;
        };
        

        RGBcolor getRGBValues ( COLORREF color ) 
        {
            RGBcolor RGB;
            RGB.R = GetRValue(color);
            RGB.G = GetGValue(color);
            RGB.B = GetBValue(color);

            return RGB;
        }

    private:

};

    color colors;

color::RGBcolor topNoApple = { 195, 134, 96 };
color::RGBcolor midNoApple = { 167, 111, 74 };
color::RGBcolor botNoApple { 193, 129, 88 };
color::RGBcolor backNoStar {};



void sendInput(char type) //"Type" is U, D, L, or R for updownleftright
{

    if ( type == 'U' )
    { 
        INPUT ip[2];

        ip[0].type = INPUT_KEYBOARD;
        ip[0].ki.wVk = VK_UP;
        ip[1].type = INPUT_KEYBOARD;
        ip[1].ki.wVk = VK_UP;
        ip[1].ki.dwFlags = KEYEVENTF_KEYUP;

        SendInput(ARRAYSIZE(ip), ip, sizeof(INPUT));
    }

    else if ( type == 'R' ) 
    {
        INPUT ip[2];

        ip[0].type = INPUT_KEYBOARD;
        ip[0].ki.wVk = VK_RIGHT;
        ip[1].type = INPUT_KEYBOARD;
        ip[1].ki.wVk = VK_RIGHT;
        ip[1].ki.dwFlags = KEYEVENTF_KEYUP;

        SendInput(ARRAYSIZE(ip), ip, sizeof(INPUT));
    }

}  

//765, 645
//167, 111, 74

void checks() 
{
        HDC dc = GetDC(NULL);
        
        COLORREF colorTop = GetPixel(dc, 735, 450);
        color::RGBcolor topCurrentPixel = colors.getRGBValues(colorTop);
        if ( topCurrentPixel == topNoApple ) {}
        else { sendInput('U'); }
        
        COLORREF colorMid = GetPixel(dc, 765, 645);
        color::RGBcolor midCurrentPixel = colors.getRGBValues(colorMid);
        if ( midCurrentPixel == midNoApple ) {}
        else { sendInput('R'); }
        
        COLORREF colorBot = GetPixel(dc, 730, 810);
        
        // color::RGBcolor botCurrentPixel = colors.getRGBValues(colorTop);
        // if ( botCurrentPixel == botNoApple ) {}
        // else { sendInput('D'); }

        COLORREF colorBack = GetPixel(dc, 0, 0);
        
        
        ReleaseDC(NULL, dc);
}

int main() 
{    
    std::this_thread::sleep_for (std::chrono::seconds(2));

    while ( true )
    {
        checks();
        

        if ( GetAsyncKeyState(VK_SPACE)  ) { break; };

        std::this_thread::sleep_for (std::chrono::milliseconds(16));
    }


        

    return 0;
}