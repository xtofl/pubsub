#include "switch.h"
#include <QRectF>
#include <QSizeF>
#include <QPainter>
#include <QDebug>

Switch::Switch(QPointF topleft, QString name, QObject* objectParent, QGraphicsItem *parent)
    : QObject(objectParent)
    , QGraphicsRectItem(topleft.x(), topleft.y(), 50., 50., parent)
    , name(std::move(name))
{
}

void Switch::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsRectItem::paint(painter, option, widget);
}

void Switch::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "pressed";
    emit clicked();
}
