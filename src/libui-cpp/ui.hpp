
#include "uidefs.hpp"
#include "../../ext/libui/ui.h"
#include <functional>

namespace ui {
    
#define UICPP_UI(TYPE,PTR) \
    TYPE PTR; \
    public: \
    uiControl* getUiControl() override { return uiControl(PTR); } \
    uiControl const* getUiControl() const override { return uiControl(PTR); } \
    private:

    
    namespace detail {
        
    } // detail
    
    class Ui
    {
    public:
        Ui(uiInitOptions*);
        ~Ui();
        
        void main();
        void quit();
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
        UICPP_UI(uiWindow*, window_);
        
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

    
    class Button : public Control
    {
        UICPP_UI(uiButton*, button_);
        
        typedef std::function<void(void*)> callback_t;
        callback_t cb_;
        void* data_;
        static void c_callback(uiButton*,void*);
        
    public:
        
        Button(const char *text = "");
        ~Button();
        
        const char* text() const;
        Button& setText(const char *text);
        
        void onClicked(callback_t const& callback, void* data = nullptr)
        {
            cb_ = callback;
            data_ = data;
            uiButtonOnClicked(button_, c_callback, this);
        }
    };
    
    
    namespace box {
    } // box
    
}