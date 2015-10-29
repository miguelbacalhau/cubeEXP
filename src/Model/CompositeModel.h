#ifndef INCLUDED_COMPOSITEMODEL
#define INCLUDED_COMPOSITEMODEL
#include <vector>
#include "Model.h"

/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */
class Visitor;

class CompositeModel : public Model {

    private:
        std::vector<Model*> _subModels;
    public:
        CompositeModel(Position position, std::vector<Model*> subModels);
        std::vector<Model*> getSubModels();
        void accept(Visitor *visitor);
};
#endif
