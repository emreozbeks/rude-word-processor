#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_process_given_sentence_button_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QNetworkRequest request;

    QWidget *central_widget;
    QVBoxLayout *outer_vertical_layout;
    QHBoxLayout *label_and_input_sentence_box_horizontal_layout;
    QLineEdit *input_sentence_box;
    QLabel *enter_a_sentence_label;
    QPushButton *process_given_sentence_button;
    QLabel *result_sentence_label;
};
#endif // MAINWINDOW_H
