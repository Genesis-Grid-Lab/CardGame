#include "Application/Application.h"

int main()
{
    auto app = new Application();
    app->RunContext(false);
    DELETE(app);
    return 0;
}
