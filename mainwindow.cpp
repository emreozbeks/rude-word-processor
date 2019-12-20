#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QNetworkReply>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QString>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager;

    // I don't know the exact reason but layout objects shouldn't have a parent, otherwise Qt gives warning.
    outer_vertical_layout = new QVBoxLayout;
    label_and_input_sentence_box_horizontal_layout = new QHBoxLayout;
    enter_a_sentence_label = new QLabel("Please Enter a Sentence: ", this);
    result_sentence_label = new QLabel("Result:");
    input_sentence_box = new QLineEdit(this);
    input_sentence_box->setPlaceholderText("Enter Your Sentence");
    process_given_sentence_button = new QPushButton("Process Sentence", this);

    central_widget = new QWidget(this);
    central_widget->setLayout(outer_vertical_layout);
    setCentralWidget(central_widget);
    outer_vertical_layout->addLayout(label_and_input_sentence_box_horizontal_layout);
    outer_vertical_layout->addWidget(process_given_sentence_button);
    outer_vertical_layout->addWidget(result_sentence_label);
    label_and_input_sentence_box_horizontal_layout->addWidget(enter_a_sentence_label);
    label_and_input_sentence_box_horizontal_layout->addWidget(input_sentence_box);

    connect(process_given_sentence_button, SIGNAL(clicked()), this, SLOT(on_process_given_sentence_button_clicked()));
}

MainWindow::~MainWindow()
{
    delete result_sentence_label;
    delete input_sentence_box;
    delete enter_a_sentence_label;
    delete process_given_sentence_button;
    delete label_and_input_sentence_box_horizontal_layout;
    delete outer_vertical_layout;
    delete central_widget;
    delete manager;
    delete ui;
}

void MainWindow::on_process_given_sentence_button_clicked()
{
}
