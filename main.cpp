#include <QApplication>
#include "cbuiltindlg.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CBuildinDlg w;
    w.show();

    return app.exec();
}
