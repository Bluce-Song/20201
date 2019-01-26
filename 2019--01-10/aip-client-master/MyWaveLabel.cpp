#include "MyWaveLabel.h"

MyWaveLabel::MyWaveLabel(QWidget *parent) :
    QLabel(parent)
{
    isSet = false;
    isValid = false;
    item = tr("未选中");
    this->setMinimumSize(WIDTH,HEIGHT);
    this->setMaximumSize(WIDTH,HEIGHT);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.05
  * brief:      更新显示
******************************************************************************/
void MyWaveLabel::updateSet(bool set)
{
    isSet = set;
}
void MyWaveLabel::updateValid(bool valid)
{
    isValid = valid;
}
void MyWaveLabel::updateText(QString text)
{
    item = text;
}
void MyWaveLabel::updateWave(QByteArray wave)
{
    int i;
    waveByte = wave;
    px.clear();
    for (i=0; i<wave.size()/2; i++) {
        px.append(height()-wave[i*2]);
    }
    this->update();
}

bool MyWaveLabel::isChecked()
{
    return isValid;
}

QByteArray MyWaveLabel::wave()
{
    return waveByte;
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.05
  * brief:      绘制label
******************************************************************************/
void MyWaveLabel::paintEvent(QPaintEvent *)
{
    int i;

    QPainter *painter = new QPainter(this);
    painter->setPen(QPen(Qt::darkGreen, 1, Qt::DotLine));

    //横线
    painter->drawLine(QPoint(0,height()*3/4),QPoint(width(),height()*3/4));
    painter->drawLine(QPoint(0,height()*2/4),QPoint(width(),height()*2/4));
    painter->drawLine(QPoint(0,height()*1/4),QPoint(width(),height()*1/4));

    //坚线
    painter->drawLine(QPoint(width()*1/4,0),QPoint(width()*1/4,height()));
    painter->drawLine(QPoint(width()*2/4,0),QPoint(width()*2/4,height()));
    painter->drawLine(QPoint(width()*3/4,0),QPoint(width()*3/4,height()));

    painter->setPen(QPen(Qt::green, 2, Qt::SolidLine));
    for(i=0; i<px.size()-1; i++)
    {
        painter->drawLine(QPoint(i,px[i]),QPoint(i+1,px[i+1]));
    }
    painter->setPen(QPen(Qt::white, 1, Qt::SolidLine));
    if (isSet && isValid) {
        painter->drawTiledPixmap(width()-30,6,24,24,QPixmap(":image/58.png"));
    }
    if (isSet && !isValid) {
        painter->drawTiledPixmap(width()-30,6,24,24,QPixmap(":image/59.png"));
    }
    if (!isSet) {
        painter->drawText(QPoint(width()-50,20),item);
    }

    painter->end();
}
void MyWaveLabel::mousePressEvent(QMouseEvent *ev)
{
    if (ev->y() < height()*1/4 && ev->x() > width()*3/4)
        isValid = !isValid;
    else if (ev->y() > height()/2)
        emit clickBom();
    else if (ev->y() < height()/2)
        emit clickTop();
    this->update();
    QLabel::mousePressEvent(ev);
}

/******************************************************************************
                                    END
******************************************************************************/
