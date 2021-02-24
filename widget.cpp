#include "widget.h"
#include "ui_widget.h"
#include <QPaintEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

// 重写绘图事件
void Widget::paintEvent(QPaintEvent *event)
{

}

