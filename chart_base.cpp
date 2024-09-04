// chart_base.cpp
#include "chart_base.h"
#include <QDebug>

Chart_Base::Chart_Base()
{
    // Initialize properties
    chartType = 0;
    ID = 0;
    paintStart = QPointF(0, 0);
    paintEnd = QPointF(0, 0);
    movable = true;
}

Chart_Base::~Chart_Base()
{
}

void Chart_Base::save(QDataStream &out) const
{
    out << chartType << ID << paintStart << paintEnd << paintChartDrawPen << paintChartFillPen << movable;
}

void Chart_Base::load(QDataStream &in)
{
    in >> chartType >> ID >> paintStart >> paintEnd >> paintChartDrawPen >> paintChartFillPen >> movable;
}
