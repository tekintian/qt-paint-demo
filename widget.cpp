#include "widget.h"
#include "ui_widget.h"
#include <QPaintEvent>
#include<QPainter>
#include<QPixmap>
#include<QDebug>
#include<QBitmap>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->resize(800,700);

// 将button放到窗口的最下面中间位置
    // 窗口的宽高   this->width()    this->height()
    // 按钮的宽高   ui->pushButton->width()  ui->pushButton->height()
    ui->pushButton->resize(100,50); // 调整按钮的大小

    // 移动button到底部中间位置
    ui->pushButton->move( (this->width()*0.5 - ui->pushButton->width()*0.5),\
        this->height() - ui->pushButton->height() );

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->update(); // 更新时就会触发绘图事件
    });


#if 0
    // 定义一个绘图设备
    QBitmap bitmap(300,300);
    // 定义一个画家  由于这里的参数是指针,所以需要传递一个bitmap的地址
    QPainter painter(&bitmap);

    painter.drawEllipse(QPoint(100,100),50,50);
    //保存图片
    bitmap.save("./mybitmap.jpg");

#endif

#if 0
    // 定义一个QImage设备
    QImage img;
    // 加载一张图片
    img.load(":/assets/img/great.jpg");
    img.scaled(1024,1024);

    int value = qRgb(255,0,0);
    for (int i=300; i<800 ;i++ ) {
        for (int j=300;j<800 ;j++ ) {
           //设置像素
            img.setPixel(i,j,value);
        }
    }

    QPainter painter2(&img);
    painter2.drawEllipse(QPoint(900,900),600,600);
    img.save("./qimg.jpg");

#endif

#if 0
    // 定义绘图设备
    QPicture picture;
    // 定义画家
    QPainter painterp;

    //记录绘图指令
    painterp.begin(&picture);

    // 画圆
    painterp.drawEllipse(100,100,100,100);

    // 结束记录绘图指令
    painterp.end();

    // 保存绘图指令
    picture.save("/tmp/pic.zl");
    qDebug("绘图指令保存成功");

#endif


}

Widget::~Widget()
{
    delete ui;
}

// 重写绘图事件   这里是 主窗口加载的时候自动调用的
void Widget::paintEvent(QPaintEvent *event)
{

#if 1
    // 定义一个画家  花图片
    QPainter *painter = new QPainter(this);


    // 定义一个图片控件
    QPixmap pix;
    pix.load(":/assets/img/fly-pig.jpg");

    // 画背景图
//     修改图片大小  和窗口一样大小
//    pix.scaled(this->width(), this->height());

//    // 画家在主窗口绘画  这里注意想要和上面的 pixmap 一致
//    painter->drawPixmap(0,0,this->width(),this->height(), pix);


    //

    pix.scaled(pix.width()*0.5, pix.height()*0.5 ); // 图片缩小一半

    static int x = 0,y=0;

    painter->drawPixmap(x, y, pix.width(), pix.height(), pix);

    x+=10;
//    y+=10;

    //超出边框后将x y回到原点
    if( x >= this->width()){
        x=0;
    }else if (y >=this->height() ) {
        y=0;
    }

    qDebug()<<"x="<<x<<" y="<<y;


    // 画家画线
    painter->drawLine(0,0,this->width(),this->height());

    //设置画笔颜色
    painter->setPen(QColor("red"));


    // 画矩形框
    painter->drawRect(50,50, 200,200);

    // 画圆
    painter->drawEllipse(180,80, 500,500);
#endif

#if 1
    // 在paintEvent事件中 重现绘图指令到主窗口
    // 定义绘图设备
    QPicture picture;
    // 定义画家
    QPainter painterp(this);
    // 加载绘图指令
    picture.load("/tmp/pic.zl");

    //画家根据绘图指令绘图
    painterp.drawPicture(10,390,picture);

#endif
}

