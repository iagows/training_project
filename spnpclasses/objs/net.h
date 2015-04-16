#ifndef NET_H
#define NET_H

#include "objs/place.h"
#include "objs/transition.h"
#include "objs/arc.h"
#include "objs/fluidplace.h"
#include "objs/timedtransition.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC Net : public AbstractData
{
public:
    Net();
    Net(int id, std::string name,
        std::vector<Place*> *places = new std::vector<Place*>(),
        std::vector<Transition*> *transitions = new std::vector<Transition*>(),
        std::vector<Arc*> *arcs = new std::vector<Arc*>());
    virtual ~Net();

    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    void add(Place* p);
    void add(Transition* t);
    void add(Arc* a);

    void removePlace(int id);
    void removeTransition(int id);
    void removeArc(int id);
/*
    Place* getPlace(int id);
    Transition* getTransition(int id);
    Arc* getArc(int id);
*/
    std::vector<Place*> * getPlaces() const;
    std::vector<Transition*> *getTransitions() const;
    std::vector<Arc*> *getArcs() const;

private:
    std::vector<Place* > *places;
    std::vector<Transition* > *transitions;
    std::vector<Arc* > *arcs;

    virtual std::string getClassNodeName();
};
}
#endif // NET_H
