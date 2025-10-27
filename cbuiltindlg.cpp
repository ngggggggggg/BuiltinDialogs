#include "cbuiltindig.h"
#include <QGridLayout>
#include <QColorDialog>
#include <QPalette>

CBuiltinDig::CBuiltinDig(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout *gridLayout = new QGridLayout(this);

    displayTextEdit = new QTextEdit(QStringLiteral("Qt的標準通用對話盒"));
    colorPushBtn    = new QPushButton(QStringLiteral("顏色對話盒"));
    errorPushBtn    = new QPushButton(QStringLiteral("錯誤訊息盒"));
    filePushBtn     = new QPushButton(QStringLiteral("檔案對話盒"));
    fontPushBtn     = new QPushButton(QStringLiteral("字體對話盒"));
    inputPushBtn    = new QPushButton(QStringLiteral("輸入對話盒"));
    pagePushBtn     = new QPushButton(QStringLiteral("頁面設定對話盒"));
    progressPushBtn = new QPushButton(QStringLiteral("進度對話盒"));
    printPushBtn    = new QPushButton(QStringLiteral("列印對話盒"));

    gridLayout->addWidget(colorPushBtn,    0, 0);
    gridLayout->addWidget(errorPushBtn,    0, 1);
    gridLayout->addWidget(filePushBtn,     0, 2);
    gridLayout->addWidget(fontPushBtn,     1, 0);
    gridLayout->addWidget(inputPushBtn,    1, 1);
    gridLayout->addWidget(pagePushBtn,     1, 2);
    gridLayout->addWidget(progressPushBtn, 2, 0);
    gridLayout->addWidget(printPushBtn,    2, 1);
    gridLayout->addWidget(displayTextEdit, 3, 0, 1, 3);

    setWindowTitle(QStringLiteral("內建對話盒展示"));
    resize(400, 300);

    // 連線按鈕
    connect(colorPushBtn,    &QPushButton::clicked, this, &CBuiltinDig::doPushBtn);
    connect(errorPushBtn,    &QPushButton::clicked, this, &CBuiltinDig::doPushBtn);
    connect(filePushBtn,     &QPushButton::clicked, this, &CBuiltinDig::doPushBtn);
    connect(fontPushBtn,     &QPushButton::clicked, this, &CBuiltinDig::doPushBtn);
    connect(inputPushBtn,    &QPushButton::clicked, this, &CBuiltinDig::doPushBtn);
    connect(pagePushBtn,     &QPushButton::clicked, this, &CBuiltinDig::doPushBtn);
    connect(progressPushBtn, &QPushButton::clicked, this, &CBuiltinDig::doPushBtn);
    connect(printPushBtn,    &QPushButton::clicked, this, &CBuiltinDig::doPushBtn);
}

void CBuiltinDig::doPushBtn()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (btn == colorPushBtn)
    {
        QPalette palette = displayTextEdit->palette();
        const QColor &color = QColorDialog::getColor(
            palette.color(QPalette::Base),
            this,
            QStringLiteral("設定背景顏色")
            );
        if(color.isValid())
        {
            palette.setColor(QPalette::Base, color);
            displayTextEdit->setPalette(palette);
        }
    }
    else
    {
        displayTextEdit->append(QStringLiteral("按下了：") + btn->text());
    }
}

CBuiltinDig::~CBuiltinDig()
{
}
