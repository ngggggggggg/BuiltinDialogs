TEMPLATE = app
TARGET = BuiltinDialogs
QT += core gui widgets printsupport   # ← 這行一定要有！

SOURCES += main.cpp \
           cbuiltindlg.cpp

HEADERS += cbuiltindlg.h
