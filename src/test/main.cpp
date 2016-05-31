
#include "../libui-cpp/ui.hpp"
#include <memory>

int main(int argc, char *argv[])
{
    {
        uiInitOptions opts = { .Size = 0 };
        ui::Ui inst(&opts);

        {
            auto w = new ui::Window("UI");
            w->show();
            
            w->setChild(new ui::Button("click me!"))
                .onClicked([&] (void*) {
                        delete w;
                        inst.quit();
                    });
            
            inst.main();
        }

    }
    
    
    return 0;
}

