#ifndef LABEL_H
#define LABEL_H

#include "abstractvisualdata.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC Label : public AbstractVisualData
{
public:
    Label();
    Label(std::string name, int x=0, int y=0);
    virtual ~Label();

    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    virtual std::string c_str(IData *data=nullptr) const;
private:
    virtual std::string getClassNodeName();
};
}
#endif // LABEL_H
