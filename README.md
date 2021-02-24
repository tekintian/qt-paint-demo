# QT  paint 绘图



## 使用paintEvent 画背景图片



1. 在头文件中声明绘图事件

   ~~~h
   public:
       Widget(QWidget *parent = nullptr);
       ~Widget();
       virtual void paintEvent(QPaintEvent *event);
   ~~~

   

2. 在源文件中实现绘图事件

   ~~~cpp
   
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
   
   ~~~



### 移动图片

在构造函数中 设置button和移动button到窗口底部中间位置, 并注册BUTTON事件,  在事件中使用 update()函数来更新绘画事件函数 paintEvent

~~~cpp

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



~~~

绘图事件实现

~~~cpp

// 重写绘图事件   这里是 主窗口加载的时候自动调用的
void Widget::paintEvent(QPaintEvent *event)
{

    // 定义一个画家  花图片
    QPainter *painter = new QPainter(this);

    // 定义一个图片控件
    QPixmap pix;
    pix.load(":/assets/img/fly-pig.jpg");

    pix.scaled(pix.width()*0.5, pix.height()*0.5 ); // 图片缩小一半

    static int x = 0,y=0;

    painter->drawPixmap(x, y, pix.width(), pix.height(), pix);

    x+=10;
//    y+=10; // 开启后图片就会朝着右下角移动

    //超出边框后将x y回到原点
    if( x >= this->width()){
        x=0;
    }else if (y >=this->height() ) {
        y=0;
    }

    qDebug()<<"x="<<x<<" y="<<y;

}

~~~















