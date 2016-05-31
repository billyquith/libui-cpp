
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

void Ui::quit()
{
    uiQuit();
}

//------------------------------------------------------------------------------
// Control

void Control::show(bool s)
{
    if (s)
        uiControlShow(getUiControl());
    else
        uiControlHide(getUiControl());
}

bool Control::showing() const
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

bool Control::enabled() const
{
    return uiControlEnabled(getUiControl()) != 0;
}

//------------------------------------------------------------------------------

//    CLS::CLS(const char *text)
//    {
//        window_ = uiNewWindow(title, width, height, hasMenubar);
//    }
//    
//    CLS::~CLS()
//    {
//        uiControlDestroy(uiControl(window_));
//    }
//
//    TYPE CLS::title() const
//    {
//        return uiWindowTitle(window_);
//    }
//
//    void CLS::setTitle(TYPE title)
//    {
//        uiWindowSetTitle(window_, title);
//    }

//------------------------------------------------------------------------------
// Button

Button::Button(const char *text)
{
    button_ = uiNewButton(text);
}

Button::~Button()
{
    uiControlDestroy(uiControl(button_));
}

const char* Button::text() const
{
    return uiButtonText(button_);
}

Button& Button::setText(const char* text)
{
    uiButtonSetText(button_, text);
    return *this;
}

void Button::c_callback(uiButton* uib, void* d)
{
    Button *b = reinterpret_cast<Button*>(d);
    b->cb_(b->data_);
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

const char* Window::title() const
{
    return uiWindowTitle(window_);
}

void Window::setTitle(const char *title)
{
    uiWindowSetTitle(window_, title);
}

bool Window::hasMargin() const
{
    return uiWindowMargined(window_);
}

void Window::useMargin(bool use)
{
    uiWindowSetMargined(window_, use);
}

//------------------------------------------------------------------------------

} // namespace ui


