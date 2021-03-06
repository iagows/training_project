#include "abstractpetriarc.h"

#include <math.h>

#include <QPen>
#include <QPainter>

#include "diagram/items/petrilabelitem.h"

const qreal Pi = 3.14;

AbstractPetriArc::AbstractPetriArc(std::string id, IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent)
    :IPetriArc(id, startItem, endItem, parent)
{
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->myColor = Qt::black;
    setPen(QPen(this->getPenColor(), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    this->myLabel = new PetriLabelItem("1", this);
    this->updateLabelPosition();
}

AbstractPetriArc::~AbstractPetriArc()
{

}

QRectF AbstractPetriArc::boundingRect() const
{
    qreal extra = (pen().width() + 20) / 2.0;

    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
            .normalized()
            .adjusted(-extra, -extra, extra, extra);
}

QPainterPath AbstractPetriArc::shape() const
{
    QPainterPath path = QGraphicsLineItem::shape();
    path.addPolygon(myHead);
    return path;
}

bool AbstractPetriArc::canConnect()
{
    return (myStartItem->isPlace() && myEndItem->isTransition()) ||
            (myStartItem->isTransition() && myEndItem->isPlace());
}

void AbstractPetriArc::updatePosition()
{
    QLineF line(mapFromItem(myStartItem, 0, 0), mapFromItem(myEndItem, 0, 0));
    setLine(line);
}

void AbstractPetriArc::updateLabel(QString str)
{
    this->myLabel->setText(str);
}

void AbstractPetriArc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //avoiding warnings ;)
    (void)option;
    (void)widget;

    if(myStartItem->collidesWithItem(myEndItem) || !canConnect())
    {
        return;
    }

    QPen myPen = pen();
    myPen.setColor(this->getPenColor());

    painter->setPen(myPen);
    painter->setBrush(this->getBrushColor());

    QLineF centerLine(myStartItem->pos(), myEndItem->pos());
    QPolygonF endPolygon = myEndItem->polygon();
    QPointF p1 = endPolygon.first() + myEndItem->pos();
    QPointF p2;
    QPointF intersectPoint;
    QLineF polyLine;

    for(int i=1; i< endPolygon.count(); ++i)
    {
        p2 = endPolygon.at(i) + myEndItem->pos();
        polyLine = QLineF(p1, p2);
        QLineF::IntersectType intersectType =
                polyLine.intersect(centerLine, &intersectPoint);
        if(intersectType == QLineF::BoundedIntersection)
            break;
        p1 = p2;
    }

    setLine(QLineF(intersectPoint, myStartItem->pos()));

    double angle = ::acos(line().dx() / line().length());
    if(line().dy() >=0 )
        angle = (Pi*2)-angle;

    this->paintHead(angle);

    painter->drawLine(line());
    painter->drawPolygon(myHead);

    if(isSelected())
    {
        painter->setPen(QPen(this->getPenColor(), 1, Qt::DotLine));
        QLineF myLine = line();
        myLine.translate(0, 4.0);
        painter->drawLine(myLine);
        myLine.translate(0, -8.0);
        painter->drawLine(myLine);
    }

    this->updateLabelPosition();
}

void AbstractPetriArc::paintHead(double angle)
{
    qreal arcSize = 10;
    QPointF arcP1 = line().p1() + QPointF(sin(angle+Pi/3)*arcSize,
                                          cos(angle+Pi/3)*arcSize);
    QPointF arcP2 = line().p1() + QPointF(sin(angle+Pi - Pi/3)*arcSize,
                                          cos(angle+Pi - Pi/3)*arcSize);

    myHead.clear();

    myHead << line().p1() << arcP1 << arcP2;
}

QColor AbstractPetriArc::getBrushColor()
{
    return myColor;
}

QColor AbstractPetriArc::getPenColor()
{
    return myColor;
}

void AbstractPetriArc::updateLabelPosition()
{
    this->myLabel->setPos((startItem()->pos().x() + endItem()->pos().x())/2, (startItem()->pos().y() + endItem()->pos().y())/2);
}
