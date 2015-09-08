#ifndef PROJECT_H
#define PROJECT_H

#include "objs/net.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC Project : public AbstractData
{
public:
    Project(std::string name);
    Project(std::string name="", std::vector<Net*> *nets = new std::vector<Net*>(),
            std::string owner="", std::string commentary="", std::string date="");
    virtual ~Project();

    void addNet(Net* net);
    Net* getNet(std::string id) const;
    std::vector<Net *> *getNets() const;
    void removeNet(std::string id);

    std::string getName() const;

    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);
private:
    virtual std::string getClassNodeName();

    std::vector<Net*> *nets;
    std::string owner;
    std::string commentary;
    std::string date;
};
}

#endif // PROJECT_H
