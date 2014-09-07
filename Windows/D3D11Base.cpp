#include <d3d11.h>
#include <d3dcommon.h>
#include <Windows.h>

#include "base/basictypes.h"
#include "base/logging.h"

static ID3D11Device *d3dDevice;
static ID3D11DeviceContext *d3dDeviceContext;

bool D3D11_Init(HWND hWnd, bool windowed, std::string *error_message) {

	// First, create the Direct3D device.

	// This flag is required in order to enable compatibility with Direct2D.
	UINT creationFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;

#if defined(_DEBUG)
	// If the project is in a debug build, enable debugging via SDK Layers with this flag.
	creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	// This array defines the ordering of feature levels that D3D should attempt to create.
	D3D_FEATURE_LEVEL featureLevels[] = {
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_1
	};
	
	if (FAILED(D3D11CreateDevice(
		nullptr,                    // specify nullptr to use the default adapter
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,                    // leave as nullptr if hardware is used
		creationFlags,              // optionally set debug and Direct2D compatibility flags
		featureLevels,
		ARRAY_SIZE(featureLevels),
		D3D11_SDK_VERSION,          // always set this to D3D11_SDK_VERSION
		&d3dDevice,
		nullptr,
		&d3dDeviceContext
		))) {
		return false;
	}

	return true;
}

void D3D11_Shutdown() {
	d3dDeviceContext->Release();
	d3dDevice->Release();
}

void D3D11_Resize(HWND window) {

}

void D3D11_SwapBuffers() {
	
}

