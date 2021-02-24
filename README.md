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

   