#include <QApplication>
#include "cbuiltindlg.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CBuiltinDig dlg;
    dlg.show();
    return app.exec();
}
