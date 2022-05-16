#include <iostream>
#include <chrono>
#include <thread>
//TODO: Get colors for mid and bot no apple. maybe change top to be a different
//pixel.
//Set your compiler to c++20!!!!!!

//Object to acess keyboard virually
INPUT ip;
ip.type = INPUT_KEYBOARD;
ip.ki.wScan = 0;
ip.ki.time = 0;
ip.ki.dwExtraInfo = 0;


class color
{
    public:
        
        struct RGBcolor
        {
            unsigned int R;
            unsigned int G;
            unsigned int B;
        
            bool operator==(const RGBcolor&) const = default;
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


color::RGBcolor topNoApple = { 195, 134, 96 };

color::RGBcolor midNoApple 
    { 
    midNoApple.R = ; //Have to check where the apple goes
    midNoApple.G = ;
    midNoApple.B = ;
    };

color::RGBcolor botNoApple 
{ 
    botNoApple.R = ; //See above
    botNoApple.G = ;
    botNoApple.B = ; 
};

color::RGBcolor backNoStar 
{ 
    backNoStar.R = 187;
    backNoStar.G = 124;
    backNoStar.B = 83;
};


void sendInput(char type) //"Type" is U, D, L, or R for updownleftright
{
    if ( type == 'U' )
    {
        ip.ki.wVk = 0x26; //Press the "UP" key
        ip.ki.dwFlags = 0; //no idea what this does tbh
        SendInput(1, &ip, sizeof(INPUT));
    }
}  

void checks(HDC dc) 
{
        COLORREF colorTop = GetPixel(dc, 25, 13);
        color::RGBcolor topCurrentPixel = color::getRGBValues(colorTop);
        if ( topCurrentPixel != color::topNoApple )
            { sendInput('U'); }
        
        COLORREF colorMid = GetPixel(dc, x, y);
        COLORREF colorBot = GetPixel(dc, x, y);
        COLORREF colorBack = GetPixel(dc, x, y);
}

int main() 
{
    while ( true )
    {
        HDC dc = GetDC(NULL);
        checks(dc);        
        ReleaseDC(NULL, dc);
        if ( GetKeyState('p') & 0x8000 ) { break; };
        std::this_thread::sleep_for (std::chrono::milliseconds(16));
    }

    return 0;
}