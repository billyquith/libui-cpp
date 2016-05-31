
#include "uidefs.hpp"
#include "../../ext/libui/ui.h"

namespace ui {
    
    namespace detail {
        
    } // detail
    
    class Ui
    {
    public:
        Ui(uiInitOptions*);
        ~Ui();
        
        void main();
    };
    
    
    class Control
    {
    protected:
        virtual ~Control() {}
        
        virtual uiControl* getUiControl() = 0;
        virtual uiControl const* getUiControl() const = 0;
        
    public:
        
        void show(bool show = true);
        bool showing() const;
        
        void enable(bool enable = true);
        bool enabled() const;
    };
    
    
    class Button : public Control
    {
        uiButton *button_;
        
    public:
        Button(const char *text = "");
        ~Button();
        
        const char* text() const;
        Button& setText(const char *text);
        
        uiControl* getUiControl() override { return uiControl(button_); }
        uiControl const* getUiControl() const override { return uiControl(button_); }
    };
    
    
    class Window : public Control
    {
        uiWindow *window_;
        
        uiControl* getUiControl() override { return uiControl(window_); }
        uiControl const* getUiControl() const override { return uiControl(window_); }
        
    public:
        Window(const char *title, int width = 200, int height = 200, bool hasMenubar = false);
        ~Window();
        
        const char* title() const;
        void setTitle(const char *title);
        
        bool hasMargin() const;
        void useMargin(bool use);
        
        template <typename C>
        C& setChild(C* child)
        {
            uiWindowSetChild(window_, child->getUiControl());
            return *child;
        }
    };
    
    
    namespace box {
    } // box
    
}