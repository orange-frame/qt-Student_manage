#ifndef TABLEPANEL_H
#define TABLEPANEL_H

#include <QMainWindow>
#include<QTableWidget>

class TablePanel : public QWidget
{
    Q_OBJECT
public:
    explicit TablePanel(QWidget * parent = nullptr);
    void setUpUi();
private slots:
    void loadModual(const QString &modulname);
private:
    QTableWidget *tableWidget;
};

#endif // TABLEPANEL_H
