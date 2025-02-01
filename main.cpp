#include"support.h"
int main()
{
    //Init support engine
    std::srand(static_cast<unsigned>(time(NULL)));
    support Support;
    //support loop
    while (Support.running())
    {
        //Update
        Support.update();
        //Render
        Support.render();
        
    }

    return 0;
}
