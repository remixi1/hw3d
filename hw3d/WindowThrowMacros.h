#pragma once

#define HWWND_EXCEPT( hr ) Window::HrException( __LINE__,__FILE__,(hr) )
#define HWWND_LAST_EXCEPT() Window::HrException( __LINE__,__FILE__,GetLastError() )
#define HWWND_NOGFX_EXCEPT() Window::NoGfxException( __LINE__,__FILE__ ) 