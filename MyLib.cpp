#include "MyLib.h"

#include <QDebug>
#include "windows.h"

MyLib::MyLib()
{

}

void MyLib::run()
{
    MessageBox(0, "new MyLib", "C++ REPL", 0);
}

void MSMessageBox(const std::string& str1, const std::string& str2)
{
#ifdef __MINGW32__
    MessageBox(0, str1.c_str(), str2.c_str(), 0);
#else
    qDebug() << "unsupported!"
#endif

}
