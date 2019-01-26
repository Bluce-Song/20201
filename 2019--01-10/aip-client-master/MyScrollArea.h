#ifndef WTSCROLLAREA_H
#define WTSCROLLAREA_H

#include <QScrollArea>
#include <QMouseEvent>
#include <QScrollBar>
class MyScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    explicit MyScrollArea(QWidget *parent = 0);
    
private:
    int startPos;
    int endPos;
protected slots:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *);
    
};

#endif // WTSCROLLAREA_H
