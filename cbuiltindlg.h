#ifndef CBUILTINDIG_H
#define CBUILTINDIG_H

#include <QDialog>
#include <QPushButton>
#include <QTextEdit>

class CBuiltinDig : public QDialog
{
    Q_OBJECT

public:
    explicit CBuiltinDig(QWidget *parent = nullptr);

private:
    QTextEdit   *displayTextEdit;
    QPushButton *colorPushBtn;
    QPushButton *errorPushBtn;
    QPushButton *filePushBtn;
    QPushButton *fontPushBtn;
    QPushButton *inputPushBtn;
    QPushButton *pagePushBtn;
    QPushButton *progressPushBtn;
    QPushButton *printPushBtn;
};

#endif // CBUILTINDIG_H
