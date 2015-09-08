#include "abstractdata.h"
#include <ctime>
spnp::AbstractData::AbstractData()
{
    this->name = "ad";
}

spnp::AbstractData::AbstractData(std::string name)
{
    this->createID();
    this->name = name;
}

spnp::AbstractData::~AbstractData()
{

}

XMLNode *spnp::AbstractData::toXML()
{
    XMLNode* node = new XMLNode(this->getClassNodeName());
    node->setAttribute("id", this->id);
    node->setAttribute("name", this->name);

    return node;
}

void spnp::AbstractData::fromXML(XMLNode *xml)
{
    this->id = xml->getAttributeL("id");
    this->name = xml->getAttributeS("name");
}

void spnp::AbstractData::createID()
{
    std::time_t result = std::time(nullptr);
    this->id = std::to_string(result) + std::to_string(std::rand()%1001);
}
