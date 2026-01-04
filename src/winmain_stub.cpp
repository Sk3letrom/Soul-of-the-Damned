#ifdef _WIN32
#ifdef NDEBUG
#include <windows.h>
extern int main();
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    return main();
}
#endif
#endif
