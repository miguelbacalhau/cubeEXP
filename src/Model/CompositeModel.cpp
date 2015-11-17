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
double CompositeModel::getSizeX() {
    return 0.0;
}
double CompositeModel::getSizeY() {
    return 0.0;
}
double CompositeModel::getSizeZ() {
    return 0.0;
}

Volume CompositeModel::getVolume() {
    Model* model;
    Volume finalVolume, subVolume;
    finalVolume.maxX = finalVolume.maxY = finalVolume.maxZ = finalVolume.minX = finalVolume.minY = finalVolume.minZ = 0.0;
    for (std::vector<Model*>::iterator subModelIt = this->_subModels.begin() ; subModelIt != this->_subModels.end(); ++subModelIt) {
        model = *subModelIt;
        subVolume = model->getVolume();
        if(subVolume.maxX > finalVolume.maxX)
            finalVolume.maxX = subVolume.maxX;
        if(subVolume.maxY > finalVolume.maxY)
            finalVolume.maxY = subVolume.maxY;
        if(subVolume.maxZ > finalVolume.maxZ)
            finalVolume.maxZ = subVolume.maxZ;
        if(subVolume.minX < finalVolume.minX)
            finalVolume.minX = subVolume.minX;
        if(subVolume.minY < finalVolume.minY)
            finalVolume.minY = subVolume.minY;
        if(subVolume.minZ < finalVolume.minZ)
            finalVolume.minZ = subVolume.minZ;
    }

    finalVolume.maxX += this->getPosition().x;
    finalVolume.minX += this->getPosition().x;
    finalVolume.maxY += this->getPosition().y;
    finalVolume.minY += this->getPosition().y;
    finalVolume.maxZ += this->getPosition().z;
    finalVolume.minZ += this->getPosition().z;

    return finalVolume;
}

/**
 * Visitor Pattern accept
 */
void CompositeModel::accept(Visitor *visitor) {
    visitor->visit(this);
}
