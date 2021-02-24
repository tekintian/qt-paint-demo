#include "widget.h"
#include "ui_widget.h"
#include <QPaintEvent>
#include<QPainter>
#include<QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->resize(800,600);
}

Widget::~Widget()
{
    delete ui;
}

// 重写绘图事件   这里是 主窗口加载的时候自动调用的
void Widget::paintEvent(QPaintEvent *event)
{

    // 定义一个画家  花图片
    QPainter *painter = new QPainter(this);

    // 定义一个图片控件
    QPixmap pix;
    pix.load(":/assets/img/tiger_th.jpeg");

    // 修改图片大小  和窗口一样大小
    pix.scaled(this->width(), this->height());

    // 画家在主窗口绘画  这里注意想要和上面的 pixmap 一致
    painter->drawPixmap(0,0,this->width(),this->height(), pix);

}

