#ifndef CBUILDINDLG_H
#define CBUILDINDLG_H

#include <QDialog>

class QTextEdit;
class QPushButton;

class CBuildinDlg : public QDialog
{
    Q_OBJECT
public:
    explicit CBuildinDlg(QWidget *parent = nullptr);

private slots:
    void handleButtonClicked();

private:
    void setupUI();
    QTextEdit *textEdit;

    QPushButton *colorBtn;
    QPushButton *bgColorBtn;
    QPushButton *errorBtn;
    QPushButton *fileBtn;
    QPushButton *fontBtn;
    QPushButton *inputBtn;
    QPushButton *pageBtn;
    QPushButton *progressBtn;
    QPushButton *printBtn;
};

#endif // CBUILDINDLG_H
