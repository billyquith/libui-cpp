
#include "uidefs.hpp"
#include "../../ext/libui/ui.h"

namespace ui {
    
    namespace detail {
        
        template <class C, typename T>
        class Property {
        public:
            
        };
        
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
    
    class Window : public Control
    {
        uiWindow *window_;
        
        uiControl* getUiControl() override { return uiControl(window_); }
        virtual uiControl const* getUiControl() const override { return uiControl(window_); }
        
    public:
        Window(const char *title, int width = 200, int height = 200, bool hasMenubar = false);
        ~Window();
    };
    
    namespace box {
        
        
        
    } // box
    
}