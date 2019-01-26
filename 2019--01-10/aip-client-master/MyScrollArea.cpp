#include "MyScrollArea.h"

MyScrollArea::MyScrollArea(QWidget *parent) :
    QScrollArea(parent)
{
}
void MyScrollArea::mousePressEvent(QMouseEvent *event)
{
    startPos = event->y();
}

void MyScrollArea::mouseMoveEvent(QMouseEvent *event)
{
    endPos = event->y();

    int pos = qAbs(endPos-startPos);

    if (pos>10) {
        int value = this->verticalScrollBar()->value();

        if (endPos > startPos) {
            value -= pos;
            this->verticalScrollBar()->setValue(value);
        }
        if (endPos < startPos) {
            value += pos;
            this->verticalScrollBar()->setValue(value);
        }
        startPos = endPos;
    }
}
