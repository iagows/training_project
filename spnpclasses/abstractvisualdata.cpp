#include "abstractvisualdata.h"

spnp::AbstractVisualData::AbstractVisualData():AbstractData()
{
    this->x = this->y = 0;
}

spnp::AbstractVisualData::~AbstractVisualData()
{

}

spnp::AbstractVisualData::AbstractVisualData(int id, std::string name, int x, int y):AbstractData(id, name)
{
    this->x = x;
    this->y = y;
}

XMLNode *spnp::AbstractVisualData::toXML()
{
    XMLNode* node = AbstractData::toXML();
    node->setAttribute("x", this->x);
    node->setAttribute("y", this->y);

    return node;
}

void spnp::AbstractVisualData::fromXML(XMLNode *xml)
{
    AbstractData::fromXML(xml);
    this->x = xml->getAttributeI("x");
    this->y = xml->getAttributeI("y");
}
