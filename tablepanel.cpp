#include "tablepanel.h"

#include<QTabWidget>
#include<QWidget>
#include<QHeaderView>
#include<QVBoxLayout>
TablePanel::TablePanel(QWidget *parent)
    : QWidget(parent)
{
    setUpUi();
}

void TablePanel::setUpUi()
{
    tableWidget= new QTableWidget(this);
    tableWidget->setColumnCount(4);
    tableWidget->setHorizontalHeaderLabels(QStringList{"s_ID","Name","sex","Height",""});
    tableWidget->horizontalHeader()->setStretchLastSection(true);
    tableWidget->verticalHeader()->setVisible(true);
    tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tableWidget);
    layout->setContentsMargins(0,0,0,0);
    setLayout(layout);
}

void TablePanel::loadModual(const QString &modulname)
{

}
