
#include "../libui-cpp/ui.hpp"
#include <memory>

int main(int argc, char *argv[])
{
    {
        uiInitOptions opts = { .Size = 0 };
        ui::Ui inst(&opts);

        {
            //auto wnd = std::unique_ptr<ui::Window>(new ui::Window("UI"));
            auto w = new ui::Window("UI");
            w->show();
            
            w->setChild(new ui::Button("click me!"));
            
            inst.main();
            
            delete w;
        }

    }
    
    
    return 0;
}

