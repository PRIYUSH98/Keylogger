#include <iostream>
#include "windows.h"
#include "Helper.h"
#include "keyconst.h"
#include "Base64.h"
#include "io.h"

using namespace std;

int main()
{
    MSG Msg;
    while(GetMessage(&Msg,NULL,0,0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return 0;
}
