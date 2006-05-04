
#ifndef _STDAFX_H_
#define _STDAFX_H_

#ifdef _WIN32
//#define _WIN32_WINNT 0x0500
#include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>


#ifdef _LINUX
#include <X11/Xlib.h>
#include <X11/Xutil.h>
//#include <X11/extensions/xf86vmode.h>
#include <X11/keysym.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <string.h>
#endif

#include <assert.h>

#ifdef __cplusplus
#include "../../Hoe/Hoe3D/include/hoe3d.h"
#include "../../Hoe/HoeGame/hoe_console.h"
#include "../../Hoe/HoeGame/hoe_engine.h"
#include "../../Hoe/HoeGame/hoe_settings.h"
#include "../../Hoe/HoeGame/hoe_app.h"
#include "../../Hoe/HoeGame/hoe_resource_mgr.h"

#endif

#endif // _STDAFX_H_
