#ifndef SWITCH_H
#define SWITCH_H

#include <QObject>
#include <QGraphicsRectItem>

class Switch : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Switch(QPointF topleft, QString name, QObject *objectParent, QGraphicsItem *parent);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void clicked();
private:
    QString name;
};

#endif // SWITCH_H
