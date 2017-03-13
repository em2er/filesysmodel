#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rootfilesysproxymodel.h"


MainWindow::MainWindow(QWidget *parent) :
      QMainWindow(parent),
      ui(new Ui::MainWindow)
{
      ui->setupUi(this);

      fsModel = new RootFileSysProxyModel(new QFileSystemModel, "/", this);
      ui->treeView->setModel(fsModel);

      connect(fsModel, SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)), this, SLOT(onFileItemSelected()));
}

MainWindow::~MainWindow()
{
      delete ui;
}

void MainWindow::onFileItemSelected()
{
      qDebug() << Q_FUNC_INFO;
      foreach (QFileInfo fi, fsModel->checkedData())
      {
            qDebug() << fi.absoluteFilePath();
      }
}
