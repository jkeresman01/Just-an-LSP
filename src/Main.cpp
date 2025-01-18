#include "core/JustAnLSPServer.h"

int main()
{
    justanlsp::JustAnLSPServer justAnLSPServer;

    justAnLSPServer.init();
    justAnLSPServer.run();
    justAnLSPServer.shutdown();
}
