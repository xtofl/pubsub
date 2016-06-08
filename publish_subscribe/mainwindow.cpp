#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStandardItemModel"
#include <QDebug>
#include "switch.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);

    switches.append(new Switch(QPointF(10, 10), "1", this, nullptr));
    switches.append(new Switch(QPointF(50, 10), "2", this, nullptr));

    for (auto s: switches)
    {
        scene.addItem(s);
        connect(s, &Switch::clicked, this, []{qDebug() << "here";});
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
