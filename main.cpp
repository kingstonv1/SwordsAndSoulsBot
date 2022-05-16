#include <Windows.h>
#include <iostream>
#include <chrono>
#include <thread>

class color
{
    public:
        
        struct RGBcolor
        {
            unsigned int R;
            unsigned int G;
            unsigned int B;
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

int main() 
{


    while ( true )
    {
        HDC dc = GetDC(NULL);
        
        COLORREF colorTop = GetPixel(dc, 25, 13);
        // COLORREF colorMid = GetPixel(dc, x, y);
        // COLORREF colorBot = GetPixel(dc, x, y);
        // COLORREF colorBack = GetPixel(dc, x, y);


        //Top wall colors: 195, 134, 96
        //Mid wall colors: 167, 111, 74
        
        ReleaseDC(NULL, dc);

        std::this_thread::sleep_for (std::chrono::milliseconds(16));
    }



    return 0;
}