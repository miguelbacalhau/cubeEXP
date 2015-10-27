#ifndef INCLUDED_COMPMODEL
#define INCLUDED_COMPMODEL
#include <vector>
#include "Model.h"

/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */
class Visitor;

class CompModel : public Model {

    private:
        std::vector<Model*> _subModels;
    public:
        CompModel(Position position, std::vector<Model*> subModels);
        std::vector<Model*> getSubModels();
        void accept(Visitor *visitor);
};
#endif
