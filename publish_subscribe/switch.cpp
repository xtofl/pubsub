#include "switch.h"
#include <QRectF>
#include <QSizeF>
#include <QPainter>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QStateMachine>
#include <QState>

Switch::Switch(QPointF topleft, QString name, QObject* objectParent, QGraphicsItem *parent)
    : QObject(objectParent)
    , QGraphicsRectItem(topleft.x(), topleft.y(), 50., 50., parent)
    , name(std::move(name))
    , fsm(new QStateMachine(this))
{
    auto on = new QState();
    auto off = new QState();
    fsm->addState(on);
    fsm->addState(off);

    on->addTransition(this, &Switch::clicked, off);
    off->addTransition(this, &Switch::clicked, on);

    fsm->setInitialState(off);

    connect(on, &QState::entered, this, &Switch::on);
    connect(off, &QState::entered, this, &Switch::off);

    connect(this, &Switch::on, this, &Switch::fill);
    connect(this, &Switch::off, this, &Switch::clear);

    fsm->start();
}

void Switch::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (full)
        painter->fillRect(boundingRect(), Qt::SolidPattern);
    else
        painter->drawRect(boundingRect());
}

void Switch::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "pressed";
    Q_ASSERT(event != nullptr);
    moving.from = event->pos();
}

void Switch::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "release";
    Q_ASSERT(event != nullptr);
    moving.to = event->pos();
    setPos(pos() + (moving.diff()));
    emit clicked();
}

void Switch::fill() { full = true; update(boundingRect()); }
void Switch::clear() { full = false; update(boundingRect()); }
