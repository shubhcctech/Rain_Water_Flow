#include "stdafx.h"
#include "Visualizer.h"
// #include "Renderer.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    Visualizer mw;
   
    mw.show();
    mw.setAnimated(true);
    return a.exec();
}
