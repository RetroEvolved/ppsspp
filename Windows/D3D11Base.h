
#include "Common/CommonWindows.h"

class Thin3DContext;

bool D3D11_Init(HWND window, bool windowed, std::string *error_message);
void D3D11_Shutdown();
void D3D11_Resize(HWND window);
void D3D11_SwapBuffers();
Thin3DContext *D3D9_CreateThin3DContext();