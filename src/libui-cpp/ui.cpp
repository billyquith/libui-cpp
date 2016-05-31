
#include "ui.hpp"
#include <stdexcept>

namespace ui
{
    
#define ERROR(MSG) throw std::runtime_error(MSG)
    
//------------------------------------------------------------------------------
// Ui

Ui::Ui(uiInitOptions* opts)
{
    auto err = uiInit(opts);
    if (err != nullptr)
    {
        uiFreeInitError(err);
        ERROR(err);
    }
}

Ui::~Ui()
{
    uiUninit();
}

void Ui::main()
{
    uiMain();
}

//------------------------------------------------------------------------------
// Control

//Control::~Control()
//{
////    uiControlDestroy(getUiControl());
//}

void Control::show(bool s)
{
    if (s)
        uiControlShow(getUiControl());
    else
        uiControlHide(getUiControl());
}

bool Control::showing()
{
    return uiControlVisible(getUiControl()) != 0;
}

void Control::enable(bool e)
{
    if (e)
        uiControlEnable(getUiControl());
    else
        uiControlEnable(getUiControl());
}

bool Control::enabled()
{
    return uiControlEnabled(getUiControl()) != 0;
}
    
//------------------------------------------------------------------------------
// Window
    
Window::Window(const char *title, int width, int height, bool hasMenubar)
{
    window_ = uiNewWindow(title, width, height, hasMenubar);
}
    
Window::~Window()
{
    uiControlDestroy(uiControl(window_));
}

//------------------------------------------------------------------------------

} // namespace ui
