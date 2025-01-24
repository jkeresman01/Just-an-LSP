#include "Core/JustAnLSPServer.h"

int main()
{
    justanlsp::JustAnLSPServer justAnLSPServer;

    justAnLSPServer.init();
    justAnLSPServer.run();
    justAnLSPServer.shutdown();
}
