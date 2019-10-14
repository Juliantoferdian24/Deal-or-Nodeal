#include <windows.h>
void starterpack()
{
    remove_scrollbar();
    fullscreen();
}
void setscreenbuffersize(int x,int y){
    char mode[128]="mode con cols=";//100 lines=32");
    char modelines[8]=" lines=";
    char numx[4],numy[4];
    sprintf(numx, "%d", x);
    sprintf(numy, "%d", y);
    strcat(&mode,numx);
    strcat(&mode,modelines);
    strcat(&mode,numy);
    system(mode);
}
void remove_scrollbar()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}
void fullscreen()
{  keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
}
