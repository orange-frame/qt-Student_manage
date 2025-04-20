#include "treepanel.h"

#include <QVBoxLayout>
#include <QAction>
#include <QInputDialog>


TreePanel::TreePanel(QWidget *parent)
    : QWidget{parent}
{
    initTreeWidget();
}

void TreePanel::onItemClicked(QTreeWidgetItem *item, int column)
{
    emit moduleSelected(item->text(column));
}

void TreePanel::showContextMenu(const QPoint &pos)
{
    currentItem = treeWidget->itemAt(pos);
    QPoint globalPos = treeWidget->viewport()->mapToGlobal(pos);
    QString nodeText = currentItem->text(0);
    if(nodeText == "教师列表"){
        QMenu *teacherMenu = new QMenu(this);
        teacherMenu->addAction("添加老师",this,[=](){
            qDebug()<< "添加老师";}
        );
        teacherMenu->exec(globalPos);
    }
    else if(nodeText == "学生列表"){
        QMenu *studentMenu = new QMenu(this);
        studentMenu->addAction("添加学生",this,[=](){
            qDebug()<< "添加学生";}
                          );
        studentMenu->exec(globalPos);
    }
    else if(currentItem == universityItem){
        contextMenu->exec(globalPos);
    }
    else if(currentItem == colledgeItem){
        QMenu colledge;
        colledge.addAction("添加教师");
        colledge.addAction("添加学生");
        colledge.exec(globalPos);
        colledge.exec(globalPos);
    }
    else if(currentItem == universityItem) {
        contextMenu->exec(globalPos);
    }
    else{
        blackMenu->exec(globalPos);
    }
}

void TreePanel::addItem()
{
    if(!currentItem) return ;
    if(currentItem == colledgeItem) return ;
    bool ok;
    QString text = QInputDialog::getText(this,"添加学院","学院名称",QLineEdit::Normal,"",&ok);
    if(ok && !text.isEmpty()){
        QTreeWidgetItem *newItem = new QTreeWidgetItem(currentItem);
        newItem->setText(0,text);

        if(currentItem == universityItem){
            QTreeWidgetItem *teacherItem = new QTreeWidgetItem(newItem);
            teacherItem->setText(0,"教师列表");

            QTreeWidgetItem *studentItem = new QTreeWidgetItem(newItem);
            studentItem->setText(0,"学生列表");
        }
        currentItem->setExpanded(true);
    }
}

void TreePanel::removeItem()
{
    if(!currentItem) return;
    if(currentItem->parent()){
        delete currentItem;
    }
}

void TreePanel::initTreeWidget()
{
    treeWidget = new QTreeWidget(this);
    treeWidget->setHeaderHidden(true);
    treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    universityItem = new QTreeWidgetItem(treeWidget);
    universityItem->setText(0,"清华大学");

    colledgeItem = new QTreeWidgetItem(universityItem);
    colledgeItem->setText(0,"计算机学院");

    QTreeWidgetItem *teacherItem = new QTreeWidgetItem(colledgeItem);
    teacherItem->setText(0,"教师列表");


    QTreeWidgetItem *studentItem = new QTreeWidgetItem(colledgeItem);
    studentItem->setText(0,"学生列表");

    connect(treeWidget,&QTreeWidget::itemClicked,this,&TreePanel::onItemClicked);
    connect(treeWidget,&QTreeWidget::customContextMenuRequested,this,&TreePanel::showContextMenu);



    contextMenu = new QMenu(this);
    contextMenu->addAction("添加学院",this,&TreePanel::addItem);
    contextMenu->addAction("删除学院",this,&TreePanel::removeItem);

    blackMenu = new QMenu(this);
    blackMenu->addAction("创建学校",this,&TreePanel::addItem);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(treeWidget);
    layout->setContentsMargins(0,0,0,0);
    setLayout(layout);
}

void TreePanel::addUniversity()
{
    bool ok;
    QString text = QInputDialog::getText(this,"创建学校","学校名称",QLineEdit::Normal,"",&ok);
    if(ok && !text.isEmpty()){
        QTreeWidgetItem *newUniverse = new QTreeWidgetItem(treeWidget);
        newUniverse->setText(0,text);
        treeWidget->setCurrentItem(newUniverse);
    }
}
