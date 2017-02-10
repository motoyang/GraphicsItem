#include "startitem.h"

StartItem::StartItem()
{
    pix.load("/Users/moto2yang/cpp/qt/basketball.png");
}

QRectF StartItem::boundingRect() const
{
    return QRectF(-pix.width()/2, -pix.height()/2, pix.width(), pix.height());
}

void StartItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(boundingRect().topLeft(), pix);
}
