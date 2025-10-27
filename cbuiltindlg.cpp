#include "cbuiltindlg.h"
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QColorDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QPrinter>
#include <QPageSetupDialog>
#include <QPrintDialog>
#include <QProgressDialog>
#include <QThread>
#include <QApplication>

CBuildinDlg::CBuildinDlg(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
    setWindowTitle("Qt 內建對話盒展示");
    resize(600, 450);
}

void CBuildinDlg::setupUI()
{
    // 建立文字區
    textEdit = new QTextEdit(this);
    textEdit->setPlainText("這是示範文字區。\n點選按鈕開啟不同內建對話盒。");

    // 建立按鈕
    colorBtn = new QPushButton("文字顏色", this);
    bgColorBtn = new QPushButton("背景顏色", this);
    errorBtn = new QPushButton("錯誤訊息盒", this);
    fileBtn  = new QPushButton("檔案對話盒", this);
    fontBtn  = new QPushButton("字型對話盒", this);
    inputBtn = new QPushButton("輸入對話盒", this);
    pageBtn  = new QPushButton("頁面設定", this);
    progressBtn  = new QPushButton("進度對話盒", this);
    printBtn  = new QPushButton("列印對話盒", this);

    QList<QPushButton*> buttons = {colorBtn, bgColorBtn, errorBtn, fileBtn, fontBtn,
                                    inputBtn, pageBtn, progressBtn, printBtn};

    for (auto btn : buttons)
        connect(btn, &QPushButton::clicked, this, &CBuildinDlg::handleButtonClicked);

    // 使用 GridLayout 排版：三行三列
    QGridLayout *gridLayout = new QGridLayout(this);
    int row = 0, col = 0;
    for (int i = 0; i < buttons.size(); ++i) {
        gridLayout->addWidget(buttons[i], row, col);
        col++;
        if (col >= 3) {
            col = 0;
            row++;
        }
    }

    // QTextEdit 放在按鈕下面，跨 3 列
    gridLayout->addWidget(textEdit, row, 0, 1, 3);

    setLayout(gridLayout);
}

void CBuildinDlg::handleButtonClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;

    QString name = btn->text();

    if (name.contains("文字顏色")) {
        QColor c = QColorDialog::getColor(Qt::black, this, "選擇文字顏色");
        if (c.isValid()) {
            QPalette p = textEdit->palette();
            p.setColor(QPalette::Text, c);
            textEdit->setPalette(p);
            textEdit->append("\n已選擇文字顏色：" + c.name());
        }
    }
    else if (name.contains("背景顏色")) {
        QColor c = QColorDialog::getColor(Qt::white, this, "選擇背景顏色");
        if (c.isValid()) {
            QPalette p = textEdit->palette();
            p.setColor(QPalette::Base, c);
            textEdit->setPalette(p);
            textEdit->append("\n已選擇背景顏色：" + c.name());
        }
    }
    else if (name.contains("錯誤")) {
        QMessageBox::critical(this, "錯誤", "這是一個錯誤訊息！");
        QMessageBox::warning(this, "警告", "這是一個警告訊息！");
        QMessageBox::information(this, "資訊", "這是一個資訊訊息！");
    }
    else if (name.contains("檔案")) {
        QString file = QFileDialog::getOpenFileName(this, "開啟檔案", "", "All Files (*.*)");
        if (!file.isEmpty())
            textEdit->append("\n選擇的檔案：" + file);
    }
    else if (name.contains("字型")) {
        bool ok;
        QFont f = QFontDialog::getFont(&ok, textEdit->font(), this, "選擇字型");
        if (ok) textEdit->setFont(f);
    }
    else if (name.contains("輸入")) {
        bool ok;
        QString text = QInputDialog::getText(this, "輸入文字", "請輸入內容：", QLineEdit::Normal, "", &ok);
        if (ok) textEdit->append("\n輸入文字：" + text);
    }
    else if (name.contains("頁面")) {
        QPrinter printer;
        QPageSetupDialog dlg(&printer, this);
        if (dlg.exec() == QDialog::Accepted)
            textEdit->append("\n頁面設定完成");
    }
    else if (name.contains("進度")) {
        QProgressDialog dlg("執行中...", "取消", 0, 100, this);
        dlg.setWindowModality(Qt::WindowModal);
        for (int i = 0; i <= 100; ++i) {
            dlg.setValue(i);
            qApp->processEvents();
            if (dlg.wasCanceled()) break;
            QThread::msleep(15);
        }
        textEdit->append("\n進度對話盒完成");
    }
    else if (name.contains("列印")) {
        QPrinter printer;
        QPrintDialog dlg(&printer, this);
        if (dlg.exec() == QDialog::Accepted)
            textEdit->print(&printer);
    }
}
