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


signals:
    void clicked();
private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    QString name;

    struct Moving {
        QPointF from;
        QPointF to;
        QPointF diff() const { return to - from;}
    };
    Moving moving;
};

#endif // SWITCH_H
