#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QGraphicsScene>
#include <QGraphicsVideoItem>
#include <QAudioOutput>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QMediaPlayer * player0 = nullptr;
    QGraphicsScene * scene0 = nullptr;
    QGraphicsVideoItem * videoItem0 = nullptr;
    QAudioOutput * audioOutput0 = nullptr;
    QMediaPlayer * player1 = nullptr;
    QGraphicsScene * scene1 = nullptr;
    QGraphicsVideoItem * videoItem1 = nullptr;
    QAudioOutput * audioOutput1 = nullptr;
    QMediaPlayer * player2 = nullptr;
    QGraphicsScene * scene2 = nullptr;
    QGraphicsVideoItem * videoItem2 = nullptr;
    QAudioOutput * audioOutput2 = nullptr;
    QMediaPlayer * player3 = nullptr;
    QGraphicsScene * scene3 = nullptr;
    QGraphicsVideoItem * videoItem3 = nullptr;
    QAudioOutput * audioOutput3 = nullptr;
    QStringList strlst;

    void playMP4();
    void resizeEvent(QResizeEvent *event);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
