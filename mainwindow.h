#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSplitter>

class TreePanel;
class TablePanel;
QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    TreePanel *treePanel;
    TablePanel *tablePanel;
    QSplitter *spliter;
};
#endif // MAINWINDOW_H
