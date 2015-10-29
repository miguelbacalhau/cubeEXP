#include <vector>
#include "CompositeModel.h"
#include "../Visitor/Visitor.h"

/**
 * Constructure
 */
CompositeModel::CompositeModel(Position position, std::vector<Model*> subModels)
    :Model(position){
    this->_subModels = subModels;
}

/**
 * Getters & Setters
 */
std::vector<Model*> CompositeModel::getSubModels() {
    return this->_subModels;
}

/**
 * Visitor Pattern accept
 */
void CompositeModel::accept(Visitor *visitor) {
    visitor->visit(this);
}
