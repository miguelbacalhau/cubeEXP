#include <vector>
#include "CompModel.h"
#include "../Visitor/Visitor.h"

/**
 * Constructure
 */
CompModel::CompModel(Position position, std::vector<Model*> subModels)
    :Model(position){
    this->_subModels = subModels;
}

/**
 * Getters & Setters
 */
std::vector<Model*> CompModel::getSubModels() {
    return this->_subModels;
}

/**
 * Visitor Pattern accept
 */
void CompModel::accept(Visitor *visitor) {
    visitor->visit(this);
}
