#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    playMP4();
}

void Widget::resizeEvent(QResizeEvent *)
{
    ui->graphicsView0->setGeometry(0,0,this->width()/2,this->height()/2);
    ui->graphicsView1->setGeometry(this->width()/2,0,this->width()/2,this->height()/2);
    ui->graphicsView2->setGeometry(0,this->height()/2,this->width()/2,this->height()/2);
    ui->graphicsView3->setGeometry(this->width()/2,this->height()/2,this->width()/2,this->height()/2);
    if(videoItem0!=nullptr) videoItem0->setSize(QSize(ui->graphicsView0->width(),ui->graphicsView0->height()));
    if(videoItem1!=nullptr) videoItem1->setSize(QSize(ui->graphicsView1->width(),ui->graphicsView1->height()));
    if(videoItem2!=nullptr) videoItem2->setSize(QSize(ui->graphicsView2->width(),ui->graphicsView2->height()));
    if(videoItem3!=nullptr) videoItem3->setSize(QSize(ui->graphicsView3->width(),ui->graphicsView3->height()));
}

void Widget::playMP4()
{
    player0 = new QMediaPlayer(this);
    scene0 = new QGraphicsScene(this);
    videoItem0 = new QGraphicsVideoItem;
    audioOutput0 = new QAudioOutput(this);
    player1 = new QMediaPlayer(this);
    scene1 = new QGraphicsScene(this);
    videoItem1 = new QGraphicsVideoItem;
    audioOutput1 = new QAudioOutput(this);
    player2 = new QMediaPlayer(this);
    scene2 = new QGraphicsScene(this);
    videoItem2 = new QGraphicsVideoItem;
    audioOutput2 = new QAudioOutput(this);
    player3 = new QMediaPlayer(this);
    scene3 = new QGraphicsScene(this);
    videoItem3 = new QGraphicsVideoItem;
    audioOutput3 = new QAudioOutput(this);
    strlst.clear();
    strlst = QFileDialog::getOpenFileNames();

    ui->graphicsView0->setScene(scene0);
    player0->setSource(QUrl::fromLocalFile(strlst.at(0)));
    videoItem0->setFlags(QGraphicsVideoItem::ItemIsMovable
                        |QGraphicsPathItem::ItemIsSelectable
                        |QGraphicsItem::ItemIsFocusable);
    scene0->addItem(videoItem0);
    videoItem0->setSize(QSize(ui->graphicsView0->width(),ui->graphicsView0->height()));
    player0->setVideoOutput(videoItem0);
    player0->setAudioOutput(audioOutput0);
    audioOutput0->setVolume(100);
    player0->play();

    ui->graphicsView1->setScene(scene1);
    player1->setSource(QUrl::fromLocalFile(strlst.at(1)));
    videoItem1->setFlags(QGraphicsVideoItem::ItemIsMovable
                        |QGraphicsPathItem::ItemIsSelectable
                        |QGraphicsItem::ItemIsFocusable);
    scene1->addItem(videoItem1);
    videoItem1->setSize(QSize(ui->graphicsView1->width(),ui->graphicsView1->height()));
    player1->setVideoOutput(videoItem1);
    player1->setAudioOutput(audioOutput1);
    audioOutput1->setVolume(100);
    player1->play();

    ui->graphicsView2->setScene(scene2);
    player2->setSource(QUrl::fromLocalFile(strlst.at(2)));
    videoItem2->setFlags(QGraphicsVideoItem::ItemIsMovable
                        |QGraphicsPathItem::ItemIsSelectable
                        |QGraphicsItem::ItemIsFocusable);
    scene2->addItem(videoItem2);
    videoItem2->setSize(QSize(ui->graphicsView2->width(),ui->graphicsView2->height()));
    player2->setVideoOutput(videoItem2);
    player2->setAudioOutput(audioOutput2);
    audioOutput2->setVolume(100);
    player2->play();

    ui->graphicsView3->setScene(scene3);
    player3->setSource(QUrl::fromLocalFile(strlst.at(3)));
    videoItem3->setFlags(QGraphicsVideoItem::ItemIsMovable
                        |QGraphicsPathItem::ItemIsSelectable
                        |QGraphicsItem::ItemIsFocusable);
    scene3->addItem(videoItem3);
    videoItem3->setSize(QSize(ui->graphicsView3->width(),ui->graphicsView3->height()));
    player3->setVideoOutput(videoItem3);
    player3->setAudioOutput(audioOutput3);
    audioOutput3->setVolume(100);
    player3->play();
}

Widget::~Widget()
{
    if(videoItem0!=nullptr) delete videoItem0;
    if(videoItem1!=nullptr) delete videoItem1;
    if(videoItem2!=nullptr) delete videoItem2;
    if(videoItem3!=nullptr) delete videoItem3;
    delete ui;
}

