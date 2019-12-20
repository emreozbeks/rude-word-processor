#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Rude Word Processor");
    w.setWindowIcon(QIcon(":/icons/window-icon.png"));
    w.setFixedSize(QSize(500, 150));
    w.show();
    return a.exec();
}
