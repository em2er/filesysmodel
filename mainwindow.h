#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class RootFileSysProxyModel;


class MainWindow : public QMainWindow
{
      Q_OBJECT

public:
      explicit MainWindow(QWidget *parent = 0);
      ~MainWindow();

private slots:
      void onFileItemSelected();

private:
      Ui::MainWindow *ui;
      RootFileSysProxyModel* fsModel ;
};

#endif // MAINWINDOW_H
